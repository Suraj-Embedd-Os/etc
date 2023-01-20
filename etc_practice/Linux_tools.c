1) file
 Help to determine the file type
 ex file /bin/ls
 
2)ldd
 Print shared object dependencies
  ex ldd /bin/ls
  
3)ltrace
A library call tracer
We now know how to find the libraries an executable program is dependent on using the ldd command. 
However, a library can contain hundreds of functions. Out of those hundreds, which are the actual 
functions being used by our binary?

ex ltrace  /bin/ls

4)Hexdump
Display file contents in ASCII, decimal, hexadecimal, or octal
ex hexdump -C /bin/ls

5)strings
Print the strings of printable characters in files

ex strings  /bin/ls

6)readelf
Display information about ELF files
ex readelf -h /bin/ls

7)objdump
 Display information from an object file
 ex objdump -d /bin/ls | head
 
8)strace
 Trace system calls and signals
 ex strace -f /bin/ls
 
9)nm
List symbols from object files

10)gdb
The GNU debugger
 
 