CC=gcc
CCFLAGS=-I./inc/ -lbluetooth
EXE=rfcomm_client
INC=$(shell find ./inc -name "*.h")
SRC=$(shell ls ./src)

LST=$(shell ls ./src | grep "bt")
OBJ:=$(SRC:%.c=./obj/%.o)

all:$(EXE)

$(EXE): $(OBJ)
	gcc  $^ -o $@ $(CCFLAGS)
	
./obj/main.o:./src/main.c  $(INC)
	$(CC) -c $< -o $@ $(CCFLAGS)

./obj/%.o:./src/%.c ./inc/%.h
	$(CC) -c $< -o $@ $(CCFLAGS)

