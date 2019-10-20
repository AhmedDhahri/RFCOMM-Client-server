#ifndef SHM_MGT
	#define SHM_MGT
	#include <stdio.h> 
	#include <stdlib.h> 
	#include <string.h> 
	#include <fcntl.h> 
	#include <sys/shm.h> 
	#include <sys/stat.h> 
	#include <sys/mman.h>

	void share_msg();
	void get_msg();
#endif
