#!/bin/bash

#remote_pid=`ps aux |grep -v grep | grep -i jetsonConnect | awk '{print $2}'`
#encoder_pid=`ps aux |grep -v grep | grep -i encoder.sh | awk '{print $2}'`

#sleep 5

while [ 1 ]
do
	#echo "helii"
	#remote_pid=`ps aux |grep -v grep | grep -i jetsonConnect | awk '{print $2}'`
	encoder_pid=`ps aux |grep -v grep | grep -i encoder | awk '{print $2}'`
	pid2=`ps aux |grep -v grep | grep -i sleep | awk '{print $2}'`
	pid=`ps aux |grep -v grep | grep -i test.sh | awk '{print $2}'`
   
   echo " pid2 $pid2  "
   echo "pid $pid "
   
   if [[ ! -n $pid2 ]] || [[ ! -n $pid ]]
   then
		break;
	fi
   
    
done

#echo "Out of the loop"

kill -9 $pid2
kill -9 $pid


