INSTDIR=/usr/local/bin

all: server client

server: server.c
	gcc -Wall -o server server.c

client: client.c
	gcc -Wall -o client client.c

install: server client
	mv server client ${INSTDIR}
 
clean:
	-rm -f server.o client.o core