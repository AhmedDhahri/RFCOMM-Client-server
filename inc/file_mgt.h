#ifndef FILE_MGT
	#define FILE_MGT
	#include <stdio.h>
	#include <stdint.h>
	#include <stdlib.h>


	FILE* file_init(const char* name);
	void file_append(uint8_t data, FILE* file);
	void file_deint(FILE* file);
	void create_JSON_file(int sock);
#endif
