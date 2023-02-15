#!/bin/bash

trap fun SIGINT

fun()
{
	 echo "ctrl+c detected"
	exit 0
}

while [[ 1 ]]
do
	sleep 1


	echo "called remote machine .sh"
done


