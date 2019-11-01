#include "bt_sdp.h"
#include "bt_spp.h"
#include "file_mgt.h"
#include <unistd.h>
#include <time.h>
#include <signal.h>


const uint8_t uuid[16] = {0xbc, 0xd4, 0x49, 0x3b, 0x5f, 0x61, 0x45, 0x36, 0xae, 0x09, 0xd2, 0x49, 0xf4, 0x4d, 0x2d, 0xa7};
const char dest[19] = "D0:FF:98:B8:D1:D0";


static void catch_function(int signo) {
    printf("Continue bitch");
    fflush(stdout);
}

int main(int argc, char** argv){
    if (signal(SIGCONT, catch_function) == SIG_ERR) {
        fputs("An error occurred while setting a signal handler.\n", stderr);
        return EXIT_FAILURE;
    }
    /*bt_adapter di = get_bt_adapter(0);
    int channel = get_channel(di, uuid, dest);
    int sock = get_spp_sock(dest, channel);
    create_JSON_file(sock);*/
    int i =0;
    while(i++<10){printf(".");fflush(stdout);sleep(1);}
    while(1){pause();}
    printf("done");
    return 0;
}
