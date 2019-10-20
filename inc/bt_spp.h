#ifndef BT_SPP
	#define BT_SPP
	#include <stdio.h>
	#include <time.h>
	#include <unistd.h>
	#include <sys/socket.h>
	#include <bluetooth/bluetooth.h>
	#include <bluetooth/rfcomm.h>


	typedef struct sockaddr_rc rc_sock;
	typedef struct hci_dev_info bt_adapter;

	typedef struct{
		rc_sock p_dev;
		int sock;
		int status;
	}SPP_SETTINGS;

	int get_spp_sock(char* dest, int channel);
	int read_write(char rw, uint8_t* data, int sock);
#endif
