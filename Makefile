CC				= gcc
AR				= ar
AR_FLAGS		= -rc
FLAGS			= -g -O2
DYN_FLAGS		= -shared -Wl,-soname,libpidcontroller.so 
LFLAGS			= -fPIC

STA_LIB_FILE	= libpidcontroller.a
DYN_LIB_FILE	= libpidcontroller.so
OBJ_FILES		= build/pid_controller.o

${STA_LIB_FILE} : ${OBJ_FILES}
	${AR} ${AR_FLAGS} ${STA_LIB_FILE} ${OBJ_FILES}

${DYN_LIB_FILE}	: ${OBJ_FILES}
	${CC} ${FLAGS} ${DYN_FLAGS} -o ${DYN_LIB_FILE} ${OBJ_FILES}

build/*.o				: src/*.c
	${CC} ${FLAGS} ${LFLAGS} -o $@ $^

all : ${STA_LIB_FILE} ${DYN_LIB_FILE}