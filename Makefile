CC				= gcc
AR				= ar
AR_FLAGS	= -rc
FLAGS			= -g -O2
CFLAGS		= -std=c99
DYN_FLAGS	= -shared -Wl,-soname,libpidcntl.so
LFLAGS		= -fPIC

INC_PATH	= ./inc
SRC_PATH	= ./src

OBJ_FILES	= p_cntl.o i_cntl.o d_cntl.o pi_cntl.o pd_cntl.o pid_cntl.o utils.o
DEMO_FILE	= pid_demo.o

%.o : $(SRC_PATH)/%.c
	$(CC) $(FLAGS) $(CFLAGS) $(LFLAGS) -I$(INC_PATH) -c -o $@ $^

libpidcntl.so : $(OBJ_FILES)
	$(CC) $(FLAGS) $(CFLAGS) $(DYN_FLAGS) -o $@ $^

libpidcntl.a : $(OBJ_FILES)
	$(AR) $(AR_FLAGS) -o $@ $^

pid_demo : $(OBJ_FILES) pid_demo.o
	$(CC) $(FLAGS) $(CFLAGS) -o $@ $^

all : libpidcntl.so libpidcntl.a pid_demo

.PHONY : clean
clean :
	rm -f libpidcntl.* *.o
