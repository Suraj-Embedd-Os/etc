#!/bin/bash
function menu {
clear
echo
echo -e "\t\t\tsonar setup configurations menu \n"
echo -e "\t1. Send Dicovery Message"
echo -e "\t2. Set Center Angle"
echo -e "\t3. Set Repeat Rate"
echo -e "\t4. Set Scan Arc Size"
echo -e "\t5. Set Step Size"
echo -e "\t6. Set Tx Pulse Width"
echo -e "\t7. Set Cable Counter Ticks"
echo -e "\t8. Set Number of Samples"
echo -e "\t9. Set Oversamples"
echo -e "\t10. Set Sample Rate"
echo -e "\t11. Set Tx Power"
echo -e "\t12. Step Motor Anti-Clockwise"
echo -e "\t13. Step Motor Clockwise"
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
       ./setCenterAngle.sh D;;
3)
        ./setRepeatRate.sh D;;
4)
        ./setScanArc.sh D;;
5)
       ./setStepSize.sh D;;
6)
       ./setTxPulse.sh D;;
7)
        echo "4";;
8)
        echo "4";;
9)
        echo "4";;
10)
        echo "4";;
11)
        echo "4";;
12)
        echo "4";;
13)
        echo "4";;		

*)
 clear
 echo "Sorry, wrong selection";;
 esac
 echo -en "\t\tHit any key to continue :"
 read -n 1 line
done