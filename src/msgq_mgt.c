#include "msgq_mgt.h"

int get_msg_id(){
    key_t key; 
    key = ftok("RFCOMM", 65); 
	return msgget(key, 0666 | IPC_CREAT); 
}

void prod_msg(int msgid, char* msg ,long id){
	msg_buffer message;
	memset(&message,0,sizeof(msg_buffer));
	message.mesg_type = id;
	memcpy(message.mesg_text,msg,100);
	msgsnd(msgid, &message, sizeof(message), 0);
}

msg_buffer cons_msg(int msgid, long id){
	msg_buffer message;
	memset(&message,0,sizeof(msg_buffer));
	msgrcv(msgid, &message, sizeof(message), id, 0);
	return message;
}

void control_msg(int msgid, char action){
	msgctl(msgid, IPC_RMID, NULL); 
}
