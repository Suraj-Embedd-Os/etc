
#!/bin/bash
if [ $# -lt 2 ]
then
	echo "usage error pass ip address"
	exit 0
fi

cd  /home/toad/AcepipeWorkspace/Sonar
gcc profilerSurvey.c command.c -o profilerSurvey
./profilerSurvey $1 $2

#gcc DiscoveryMessage.c -o DiscoveryMessage

#./DiscoveryMessage && ./profilerSurvey
