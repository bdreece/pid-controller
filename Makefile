CC				= gcc
AR				= ar
AR_FLAGS	= -rc
FLAGS			= -g -O2 -w
CFLAGS		= -std=c99
DYN_FLAGS	= -shared -Wl,-soname,libpidcntl.so
LFLAGS		= -fPIC

BIN_PATH	= ./bin
INC_PATH	= ./inc
LIB_PATH 	= ./lib
SRC_PATH	= ./src

OBJ_FILES	= p_cntl.o i_cntl.o d_cntl.o pi_cntl.o pd_cntl.o pid_cntl.o utils.o

default: all

%.o: $(SRC_PATH)/%.c
	$(CC) $(FLAGS) $(CFLAGS) $(LFLAGS) -I$(INC_PATH) -c -o $@ $^

$(LIB_PATH)/libpidcntl.so: $(OBJ_FILES)
	$(CC) $(FLAGS) $(CFLAGS) $(DYN_FLAGS) -o $@ $^

$(LIB_PATH)/libpidcntl.a: $(OBJ_FILES)
	$(AR) $(AR_FLAGS) -o $@ $^

$(BIN_PATH)/pid_demo: pid_demo.o $(LIB_PATH)/libpidcntl.a
	$(CC) $(FLAGS) $(CFLAGS) -I$(INC_PATH) -o $@ $^

all: $(LIB_PATH)/libpidcntl.so $(LIB_PATH)/libpidcntl.a $(BIN_PATH)/pid_demo clean

.PHONY: clean
clean:
	rm -f *.o

.PHONY: remove
remove: clean
	rm $(BIN_PATH)/* $(LIB_PATH)/*
