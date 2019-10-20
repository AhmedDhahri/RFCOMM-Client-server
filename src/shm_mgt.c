#include "shm_mgt.h"


const int SIZE = 4096; 
const char* name = "rfcomm_client";

void share_msg(){
	const char* message = "Hello World!"; 
	int shm_fd;
	void* ptr;
	shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
	ftruncate(shm_fd, SIZE);
	ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
	sprintf(ptr, "%s", message);
}

void get_msg(){ 
    int shm_fd; 
    void* ptr;
    shm_fd = shm_open(name, O_RDONLY, 0666);
    ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
    printf("%s", (char*)ptr);
    shm_unlink(name); 
} 
