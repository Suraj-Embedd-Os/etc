CC	= gcc
CFLAG	= -Wall
OBJS	=	t.o musum.o
INCLUDE =	-Ipath 

all:	mk1 install

mk1:	$(OBJS)
		$(CC) $(CFLAG) -o t $(OBJS) $(INCLUDE)
		
t.o:	t.c type.h
		$(CC) -c t.c
musum.o:	musum.c type.h
		$(CC)	-c musum.c

install:	mk1
			echo install mk1 to ../bin
			mv mk1 ../bin
run:	install

clean: 
		rm -f *.o 2> /dev/null
		rm -f ../bin/mk1

		