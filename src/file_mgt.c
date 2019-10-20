#include "file_mgt.h"

FILE* file_init(const char* name){
	FILE* file =  fopen(name,"wb+");
	return file;
}

void file_append(uint8_t data, FILE* file){
	fputc(data,file);
}

void file_deint(FILE* file){
	fclose(file);
}

void create_JSON_file(int sock){
	int file_array_size;
    read_write_32('r', &file_array_size, sock);
	FILE* f =  file_init("file_array.json");
    uint8_t data;
    printf("%d",file_array_size);
    for(int i=0;i<file_array_size;i++){
		if(read_write('r', &data, sock) == -1){printf("Network error! ");exit(1);}
		file_append(data,f);
	}
	file_deint(f);
}
