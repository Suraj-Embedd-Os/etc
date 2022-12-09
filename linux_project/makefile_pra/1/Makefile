# Rule 1
program:	object.o
	gcc -o program object.o
# Rule 2
source.c:
	echo 'main() {}' > $@
# Rule 3
object.o:	source.c
	gcc -c source.c -o $@
# Rule 4
program2:	program2.c
	gcc -o program2 program2.c

