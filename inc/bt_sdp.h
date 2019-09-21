#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>
#include <bluetooth/sdp.h>
#include <bluetooth/sdp_lib.h>

typedef struct{
    bdaddr_t bdaddr;
    uuid_t root_uuid;
    sdp_list_t *attrid;
    sdp_list_t *search;
    sdp_list_t *seq;
}SDP_SETTINGS;

typedef struct hci_dev_info bt_adapter;


bt_adapter get_bt_adapter(int dev_id);
int uuidcmp(uint8_t* org, uint8_t* cmp);
int get_channel(bt_adapter di, uint8_t* uuid, char* dest);
