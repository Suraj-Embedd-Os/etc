#!/bin/bash
function menu {
clear
echo
echo -e "\t\t\tTX Pulse Width Size \n"
echo -e "\t1. 2us"
echo -e "\t2. 4us"
echo -e "\t3. 8us"
echo -e "\t4. 12us"
echo -e "\t5. 16us"
echo -e "\t6. 20us"
echo -e "\t0. Exit menu\n"
echo -en "\t\tEnter option: "
read   option
}
while [ 1 ]
do
menu
case $option in
0)
        break ;;
1)
        #todo
       ./test D;;
2)
        echo "2";;
3)
        echo "3";;
4)
        echo "4";;
5)
        echo "3";;
6)
        echo "4";;

*)
        clear
 echo "Sorry, wrong selection";;
 esac
 echo -en "\t\tHit any key to continue :"
 read -n 1 line
done