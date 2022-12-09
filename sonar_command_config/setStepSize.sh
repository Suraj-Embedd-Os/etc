#!/bin/bash
function menu {
clear
echo
echo -e "\t\t\tStep Size \n"
echo -e "\t1. 0.9 "
echo -e "\t2. 1.8"
echo -e "\t3. 2.7"
echo -e "\t4. 3.6"
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

*)
        clear
 echo "Sorry, wrong selection";;
 esac
 echo -en "\t\tHit any key to continue :"
 read -n 1 line
done