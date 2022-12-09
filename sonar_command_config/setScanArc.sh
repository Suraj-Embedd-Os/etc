#!/bin/bash
function menu {
clear
echo
echo -e "\t\t\tScan Arc angle \n"
echo -e "\t1. Set 30 degree"
echo -e "\t2. Set 60 degree"
echo -e "\t3. Set 90 degree"
echo -e "\t4. Set 120 degree"
echo -e "\t5. Set 150 degree"
echo -e "\t6. Set 180 degree"
echo -e "\t7. Set 210 degree"
echo -e "\t8. Set 240 degree"
echo -e "\t9. Set 270 degree"
echo -e "\t10.Set 330 degree"
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
        echo "5";;
6)
        echo "6";;
7)
        ;;
8)
        ;;

9)
        ;;

10)
        echo "10";;
*)
        clear
 echo "Sorry, wrong selection";;
 esac
 echo -en "\t\tHit any key to continue :"
 read -n 1 line
done