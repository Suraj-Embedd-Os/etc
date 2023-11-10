
CC=gcc
LIB_SOURCE_FILE= ../$(wildcart module*.c)
LIB_OBJECTS_FILE= $(LIB_SOURCE_FILE:.c=.o)

CCFLAGS= -Wall 

hello:	main.c ${LIB_OBJECTS_FILE}
		${CC} main.c ${LIB_OBJECTS_FILE} -o $@ -i../
		
%.o:%.c
	${CC} -c ${CCFLAGS} $^


			
			