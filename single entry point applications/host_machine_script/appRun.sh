#!/bin/bash
dialog --title "Please answer" --yesno "Do you want to run applictions?" 12 25
input=$?
clear
	if [[ $input -eq 0 ]]
	then
	gnome-terminal -- sh /home/toad2/Desktop/encoder.sh
	P1=$!
	sh /home/toad2/Desktop/jetsonConnect.sh 
	P2=$!
	wait $P1 $P2
fi
