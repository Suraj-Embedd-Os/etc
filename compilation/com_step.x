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
 
 
 Dynamic Library Soname
 library soname = lib + <library name> + .so + <library major version digit(s)>
 
 $ gcc -shared <list of object files> -Wl,-soname,libfoo.so.1 -o libfoo.so.1.0.0
 
 Linux Build Time Library Location Rules Details
gcc main.o -L../sharedLib -lworkingdemo -o demo
 gcc -Wall -fPIC main.cpp -Wl,-L../sharedLib -Wl,-lworkingdemo -o demo
