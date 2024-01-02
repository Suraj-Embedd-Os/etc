#!/bin/bash

  ./EncoderSend &
 pid1=$! 

./EncoderFIFO


echo 
echo 
#echo "pid1 $pid1 "
kill -9 $pid1


