Creating Linux Static Library
gcc -c *.c

ar rcs libstaticlib.a *.o

Converting Static to Dynamic Library
ar -x <static library>.a


Creating the Dynamic Library in Linux
The process of building dynamic libraries has traditionally consisted of the following minimum set of flags:
•	 -fPIC compiler flag
•	 -shared linker flag

 gcc -fPIC -c *.c
 gcc -shared *.o -o libdynamiclib.so