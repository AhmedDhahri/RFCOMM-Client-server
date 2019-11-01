#include <stdio.h> 
#include <string.h>
#include <sys/ipc.h> 
#include <sys/msg.h> 

  
typedef struct{ 
    long mesg_type; 
    char mesg_text[100]; 
}msg_buffer; 
