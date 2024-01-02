

#!/bin/bash
if [ $# -lt 2 ]
then
	echo "usage error pass <ip address> <manhole_ID> "
	exit 0
fi

#check folder are created or not with manhole_ID
path_to_save="/media/toad/Data2/AcePipe_Data/"
path_to_save+=$2
path_to_save+="/sweep_data/"
 mkdir -p $path_to_save

<<comment
default_manhole_ID="00000000"

read -p "Enter the manhole ID : " manhole_ID
if [[ ! -n "$manhole_ID" ]]
then
	manhole_ID=$default_manhole_ID;
fi


#ip_address=192.168.60.209
path_to_save+=$manhole_ID
path_to_save+="/sweep_data/"

mkdir -p $path_to_save
count=0
<<comment
while [[ ! -d $path_to_save  &&  $count -lt 10 ]]
do
	echo "folder not yet created"
	count=$(( $count + 1 ))
	
	if [[ $count -eq 10 ]]
	then 
		echo "going to exit "
		exit 0
	fi
	
	sleep 2
done
comment

echo "folder created at $path_to_save"


cd  /home/toad/AcepipeWorkspace/Sonar
DIR="/home/toad/AcepipeWorkspace/Sonar/build"
if [[ ! -d  $DIR ]] #check build directory is present
then
	mkdir /home/toad/AcepipeWorkspace/Sonar/build
fi

gcc profilerSurvey.c command.c -o ./build/profilerSurvey -lm
/home/toad/AcepipeWorkspace/Sonar/build/profilerSurvey $1 $path_to_save # $1 =sonar_ip , $2= manhole_ID(folder to save data)

#gcc profilerSurvey.c command.c -o profilerSurvey -lm
#./profilerSurvey $ip_address $path_to_save 

#sleep  1

#python3 ./graph2.py $path_to_save

#gcc DiscoveryMessage.c -o DiscoveryMessage

#./DiscoveryMessage && ./profilerSurvey



