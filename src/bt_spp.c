#include "bt_spp.h"



int get_spp_sock(char* dest, int channel){
    SPP_SETTINGS spp_v;
    memset(&spp_v,0,sizeof(SPP_SETTINGS));
    spp_v.sock = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);
    spp_v.p_dev.rc_family = AF_BLUETOOTH;
    spp_v.p_dev.rc_channel = (uint8_t) channel;
    str2ba(dest, &spp_v.p_dev.rc_bdaddr );
    spp_v.status = connect(spp_v.sock, (struct sockaddr *)&spp_v.p_dev, sizeof(spp_v.p_dev));
    if(spp_v.status < 0)
        return -1;
    else
        return spp_v.sock;
}

int main1(){
    //FILE* rec =  fopen("rec.jpg","w+");

    //uint8_t* bo;
    //uint8_t* bi = (int*)malloc(sizeof(uint64_t));
/*
    uint64_t k;
    int n = 0;
    char* msg = "Hi";
    // send a message
    printf("reciving ...");
    do{
        printf("\nn = %d \t",n++);*/
        //status = read(s,&bo,1);
        /*printf("%d",bo);
        fwrite(&bo,1,1,rec);
    }while(status >= 0 && n<126482);
    fclose(rec);
    do {
        printf("\nSend: ");
        scanf("%x",&k);
        *bi = k;
        printf("\nSending %Lu -- %X ... ",k);*/
        //status = write(s, bi, 8);
        /*sleep(1);

    }while( status >= 0 );

    if( status < 0 ) {
        printf("\n ERROR!");*/
        //close(s);
   /* }*/
    //return 0;
}
int read_write(char rw, uint8_t* data, int sock){
    switch(rw){
        case 'r':
            return read(sock, &data, 1);
            break;
        case 'w':
            return write(sock, data, 1);
            break;
        default:
            close(sock);
            return -1;
    }
}
