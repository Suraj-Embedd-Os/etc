
#module1.o:module1.c module1.h
#		gcc -c module1.c
			
#module2.o:module2.c module2.h
#		gcc -c module2.c
			
#module3.o:module1.c module3.h
#		gcc -c module3.c
			
#main.o:main.c
#		gcc -c main.c
		
#hello:main.o module1.o module2.o module3.o
#		gcc main.o module1.o module2.o module3.o -o hello



LIB_SOURCE_FILES= $(wildcard module*.c)
LIB_OBJECT_FILE= $(LIB_SOURCE_FILES:.c=.o)

ALL_TEXT_FILE=$(shell ls *.c)
CC=gcc
#AR=ar
LINK_OPTS= -L. -lhello.so
SOLINKFLAGS= -shared -o 

ifeq ($(DEBUG),true)
CCFLAGS=-Wall -g
SOCCFLAGS=-Wall -g -c -fPIC
else
CCFLAGS=-Wall
SOCCFLAGS=-Wall -c -fPIC
endif

%.o:%.c
		${CC} ${CCFLAGS} -c $^

hello:main.o libhello.so
		${CC} main.o -o $@ ${LINK_OPTS}


	
libhello.so:${LIB_OBJECT_FILE}
		 ${CC} ${SOLINKFLAGS} $@ ${LIB_OBJECT_FILE}

${LIB_OBJECT_FILES}: ${LIB_SOURCE_FILES}
					${CC} ${SOCCFLAGS} $^

		
clean:
		rm -rf hello libhello.so *.o

			
			