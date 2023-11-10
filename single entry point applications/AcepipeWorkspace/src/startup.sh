#!/bin/bash

# Usage:
#   copy this file to catkin_ws/src directory 
#   Run the script using bash src/startup.sh from your catkin_ws
YES=1
NO=0
cree_led_check=$YES 	#only check if not able to run, if YES not let other application run as well
sonar_check=$YES 	#only check if not able to run, if YES not let other application run as well
run_sonar=$YES		#launch soanr or not
run_led=$YES			#launch Cree Led or not
run_lidar=$YES		#launch Lidar or not

export OPENBLAS_CORETYPE=ARMV8
if [[ $run_led -eq $YES ]] 
	then
	if [[ ! -w /dev/ttyACM0 && ! -r /dev/ttyACM0 ]] #check permission ttyACM0 are read write mode if not change to read write
		then
			echo "86yxfURVtbA5" | sudo -S  chmod 666 /dev/ttyACM0
	fi
fi
path_to_save="/media/toad/Data2/AcePipe_Data"

# index of data read from setup.conf
SONAR_IP=0
PWM_CHANNEL=1
input="/home/toad/AcepipeWorkspace/src/setup.conf"
declare -A dataArray
count=0
while read -r line
        do
                dataArray[$count]=`echo $line | awk -F '=' '{print  $2}'`
                count=$[ $count + 1 ]

 done < $input
 echo "read from setup.cofig file"
 echo "sonar ip ::${dataArray[$SONAR_IP]}"
 echo "Cree Led Pwm channel ::${dataArray[$PWM_CHANNEL]}"
process_id=
LED_OFF=-1
LED_ON=0
<<commment
default_sonar_ip="192.168.60.209" #default sataic ip of sonar
read -p "Enter IP Address of the ethernet connected to SONAR " sonar_ip

if [[ ! -n "$sonar_ip" ]]
then
	sonar_ip=$default_sonar_ip;
fi

echo "sonar ip adress $sonar_ip "
commment
test_var=${dataArray[$PWM_CHANNEL]}
trap 'sig_handler' SIGINT
sig_handler()
{
	echo "Ctrl+c catch going to teminate system"
	if [[ $run_led -eq $YES ]]
		then
		python3 /home/toad/AcepipeWorkspace/LEDControl.py $LED_OFF  $test_var #${dataArray[$PWM_CHANNEL]} # pass -1  to turn off crew LED
	fi
	if [[ $run_sonar -eq $YES ]]
		then
		kill -9 $sonar_pid
	fi
	kill -9 $lidar_pid
	read -p "Enter any key to Exit: " key
	exit 0
}

if [[ $run_led -eq $YES ]] 
	then
		echo "Going to turn on Cree Led "
		python3 /home/toad/AcepipeWorkspace/LEDControl.py $LED_ON ${dataArray[$PWM_CHANNEL]}
		Cree_Status=$?
		echo "Cree_Status::$Cree_Status"	
		if [[ $cree_led_check -eq $YES ]] && [[ $Cree_Status -ne 0 ]] 
			then
			echo "unable to connect pixhawn controller"
			read -p "Enter any key to Exit: " key
			exit 0
		fi
fi



default_manhole_ID="00000000"
read -p "Enter the manhole ID : " manhole_ID
if [[ ! -n "$manhole_ID" ]]
then
	manhole_ID=$default_manhole_ID;
fi



 mkdir -p $path_to_save/$manhole_ID
echo "Create folder with name $path_to_save/$manhole_ID"

cd  /home/toad/AcepipeWorkspace
source ./devel/setup.bash

if [[ $run_sonar -eq $YES ]]
	then
		echo "Going to launch sonar application "
		 coproc /home/toad/AcepipeWorkspace/src/sonar.sh ${dataArray[$SONAR_IP]} $manhole_ID #run in background
		
	#/home/toad/AcepipeWorkspace/src/sonar.sh $sonar_ip $manhole_ID  & #run in background
	sleep 1
	#Read pid of sonar application
	sonar_pid=`ps au | grep -v grep |grep  "profilerSurvey" | awk '{print $2}'`
	echo "sonar_pid $sonar_pid"
	if [[ $sonar_check -eq $YES ]] && [[ ! -n  $sonar_pid ]]
		then 
				echo "sonar application not able to start"
				echo "Going to delete folder name with $manhole_ID"
				echo "86yxfURVtbA5" | sudo -S rm -rf $path_to_save/$manhole_ID
				read -p "Enter any key to Exit: " key
				exit 0
	fi

fi


if [[ $run_lidar -eq $YES ]] 
	then
		echo "Going to launch lidar and camera application"
		 python3 /home/toad/AcepipeWorkspace/src/lidar_pcap.py $manhole_ID  &
		#Read pid of lidar pcap application
		lidar_pid=`ps au | grep -v grep |grep  "lidar_pcap.py" | awk '{print $2}'`
		if [[ ! -n $lidar_pid ]]
			then
				echo "unable to launch lidar application"
				echo "Going to delete folder name with $manhole_ID"
				echo "86yxfURVtbA5" | sudo -S rm -rf $path_to_save/$manhole_ID
				read -p "Enter any key to Exit: " key
				exit 0
		fi
		 roslaunch ouster_ros ouster.launch manhole_id:=$manhole_ID 
	else
	echo "lidar and camera are not set to start"
fi

#This line never reach unless lidar or camera not able open	
if [[ $run_lidar -eq $YES ]] 
	then		
	echo  "Camera not able to open going to exit"
	

	#Switch off Cree Led if on
	echo "Cree Led going to Switch off "
	echo "86yxfURVtbA5" | sudo -S python3 /home/toad/AcepipeWorkspace/LEDControl.py $LED_OFF ${dataArray[$PWM_CHANNEL]}
	echo "Sonar going to killed"
	kill -9 $sonar_pid #kill sonar if running
	echo "Going to delete folder name with $manhole_ID"
	echo "86yxfURVtbA5" | sudo -S rm -rf $path_to_save/$manhole_ID #delete folder if created
	read -p "Enter any key to Exit: " key
	exit 0
fi











