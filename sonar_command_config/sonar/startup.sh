#!/bin/bash

# Usage:
#   copy this file to catkin_ws/src directory 
#   Run the script using bash src/startup.sh from your catkin_ws
process_id=10000
default_sonar_ip= "169.254.237.110" //default sataic ip of sonar
read -p "Enter IP Address of the ethernet connected to SONAR" sonar_ip
if [! -n "$sonar_ip" ]
then
	sonar_ip=$default_sonar_ip;
fi

trap 'sig_handler' SIGINT

sig_handler()
{
	#kill -9 $process_id
	python3 /home/toad/AcepipeWorkspace/LEDControl.py -1 # pass -1  to turn off crew LED
	
	exit 0
}

manhole_ID="00000000"
source ./devel/setup.bash

python3 /home/toad/AcepipeWorkspace/LEDControl.py 0  # run in background

echo "Enter the manhole ID :"
read manhole_ID
[ -n "$manhole_ID" ] &&  manhole_ID=$manhole_ID
manhole_ID="${manhole_ID:-${Default_ID}}"

#coproc /home/toad/AcepipeWorkspace/script/sonar.sh $sonar_ip $manhole_ID
#process_id=$!
roslaunch ouster_ros ouster.launch manhole_id:=$manhole_ID 








