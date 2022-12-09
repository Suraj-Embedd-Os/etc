
#!/bin/bash
#if [ $# -lt 2 ]
#then
#	echo "usage error pass <IP address> <PATH>"
#	exit 0
#fi

#cd  /home/toad/AcepipeWorkspace/Sonar
rm profilerSurvey
eth_ip_addr="192.168.60.209"
gcc profilerSurvey.c command.c sonar_calculations.c ScanSetting.c -o profilerSurvey -lm
./profilerSurvey $eth_ip_addr

#gcc DiscoveryMessage.c -o DiscoveryMessage

#./DiscoveryMessage && ./profilerSurvey
