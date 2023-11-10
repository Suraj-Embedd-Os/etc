#!/bin/bash
clear
path_to_save="/home/toad2/Desktop"
default_manhole_ID="00000000"
read -p "Enter the manhole ID : " manhole_ID	

if [ ! -n "$manhole_ID" ]
then
	manhole_ID=$default_manhole_ID;
fi

echo "manhole_ID $manhole_ID "
mkdir -m 777 $path_to_save/$manhole_ID 

#gcc -o /home/toad2/Desktop/EncoderSourceCode/build/encoderFIFO /home/toad2/Desktop/EncoderSourceCode/EncoderFIFO.c
#gcc -o /home/toad2/Desktop/EncoderSourceCode/build/encoderSend /home/toad2/Desktop/EncoderSourceCode/EncoderSend.c

gcc -o /home/toad2/Desktop/encoder /home/toad2/Desktop/Encoder.c


cd /home/toad2/Desktop/${manhole_ID}

/home/toad2/Desktop/encoder
  
#/home/toad2/Desktop/EncoderSourceCode/build/EncoderSend &
#EncoderSendPID=$! 






