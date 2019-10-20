CC=gcc
CCFLAGS= -w -I./inc/ -lbluetooth -lrt
EXE=rfcomm_client

INC=$(shell find ./inc -name \*.h)
SRC=$(shell ls ./src)
OBJ:=$(SRC:%.c=./obj/%.o)
OBJ+=./obj/main.o


all:$(EXE)

$(EXE): $(OBJ)
	@echo "Linking rfcomm_client ..."
	@gcc -o $@ $^ $(CCFLAGS)
	
./obj/main.o: main.c ./inc/bt_sdp.h ./inc/bt_spp.h ./inc/file_mgt.h ./inc/shm_mgt.h 
	@echo "Compiling main.c ..."
	@$(CC) -c $< -o $@  $(CCFLAGS)

./obj/bt_sdp.o: ./src/bt_sdp.c ./inc/bt_sdp.h
	@echo "Compiling bt_sdp.c ..."
	@$(CC) -c $< -o $@ $(CCFLAGS)

./obj/bt_spp.o: ./src/bt_spp.c ./inc/bt_sdp.h
	@echo "Compiling bt_spp.c ..."
	@$(CC) -c $< -o $@ $(CCFLAGS)
	
./obj/file_mgt.o: ./src/file_mgt.c ./inc/file_mgt.h
	@echo "Compiling file_mgt.c ..."
	@$(CC) -c $< -o $@ $(CCFLAGS)
	
	
./obj/shm_mgt.o: ./src/shm_mgt.c ./inc/shm_mgt.h
	@echo "Compiling shm_mgt.c ..."
	@$(CC) -c $< -o $@ $(CCFLAGS)
	
clean:
	@echo "Cleaning ..."
	@rm -rf ./obj/*.o
	@rm -rf ./rfcomm_client
