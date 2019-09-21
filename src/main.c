#include "bt_sdp.h"
#include "bt_spp.h"

const uint8_t uuid[16] = {0xbc, 0xd4, 0x49, 0x3b, 0x5f, 0x61, 0x45, 0x36, 0xae, 0x09, 0xd2, 0x49, 0xf4, 0x4d, 0x2d, 0xa7};
const char dest[19] = "D0:FF:98:B8:D1:D0";

int main(int argc, char **argv){
    bt_adapter di = get_bt_adapter(0);
    int channel = get_channel(di, uuid, dest);
    int sock = get_spp_sock(dest, channel);
    uint8_t* data = malloc(1);
    *data = 0x80;
    int stat;
    stat = read_write('r', data, sock);
    printf("\nstat: %d\ndata: %d",stat,*data);

    stat = read_write('w', data, sock);
    printf("\nstat: %d\ndata: %d",stat,*data);

    return 0;
}
