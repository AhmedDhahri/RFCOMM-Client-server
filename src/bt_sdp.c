#include "bt_sdp.h"



bt_adapter get_bt_adapter(int dev_id){
    bt_adapter di;
    if(hci_devinfo(dev_id, &di) < 0){
        printf("HCI device info failed");
        exit(1);
    }
    return di;
}
int get_channel(bt_adapter di, uint8_t* uuid, char* dest){
    uint32_t range = 0xffff;
    sdp_session_t *sess;
    SDP_SETTINGS sdp_v;
    memset(&sdp_v,0,sizeof(sdp_v));
    str2ba(dest,&(sdp_v.bdaddr));
    sdp_uuid16_create(&(sdp_v.root_uuid), PUBLIC_BROWSE_GROUP);
    sdp_v.attrid = sdp_list_append(NULL, &range);
    sdp_v.search = sdp_list_append(NULL, &(sdp_v.root_uuid));

    if(!(sess = sdp_connect(&di.bdaddr, &(sdp_v.bdaddr), SDP_RETRY_IF_BUSY))) {
        printf("Failed to connect to SDP server");
        return -1;
    }
    if(sdp_service_search_attr_req(sess, sdp_v.search, SDP_ATTR_REQ_RANGE, sdp_v.attrid, &(sdp_v.seq)) < 0){
        printf("SDP service search Failed");
        sdp_close(sess);
        return -1;
    }

    sdp_list_free(sdp_v.attrid, NULL);
    sdp_list_free(sdp_v.search, NULL);

  // Loop through the list of services
    for(; sdp_v.seq; sdp_v.seq = sdp_v.seq->next){
        sdp_record_t *rec = (sdp_record_t *) sdp_v.seq->data;
        sdp_list_t *access = NULL;
        int channel;
        sdp_get_access_protos(rec, &access);
        if(access){
            if(rec->svclass.type == SDP_UUID128){
                //sdp_record_print(rec);
                channel = sdp_get_proto_port(access, RFCOMM_UUID);
                /*printf("Channel: %d\n", channel);
                printf("UUID: :");
                for(int i=0;i<16;i++)
                    printf("%02X:",(uint8_t)(rec->svclass.value.uuid128.data[i]));*/
                if(uuidcmp(uuid, rec->svclass.value.uuid128.data)){
                    free((sdp_v.seq));
                    sdp_close(sess);
                    return channel;
                }
            }
        }
    }


    return -1;
}
int uuidcmp(uint8_t* org, uint8_t* cmp){
    for(int i=0;i<16;i++){
        if(org[i]!=cmp[i]){
            return 0;
        }
    }
    return 1;
}
