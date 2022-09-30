hostname="os-992109000066.local"
lidar_port=7502
imu_port=7503
from contextlib import closing
from more_itertools import time_limited
from ouster import client,pcap
import datetime
import os
import sys
import time


path_base="/media/toad/Data2/AcePipe_Data/"
#manholId=str(input("Enter manholId "))
time.sleep(2)


length=int(len(sys.argv))
if length!=2:
    print("Usage error pass <manholId >")
    exit(0)
manholId=str(sys.argv[1])



path_base +=f"{manholId}/"
print(path_base)


isExist = os.path.exists(path_base)
if isExist!=True:
	print(isExist)
	sys.exit("Not found directory")
	
print(f"pcap data save locations {path_base} ")




 # connect to sensor and record lidar/imu packets
with closing(client.Sensor(hostname, lidar_port, imu_port,buf_size=640)) as source:

     # make a descriptive filename for metadata/pcap files
    time_part = datetime.datetime.now().strftime("%Y%m%d_%H%M%S")
    meta = source.metadata
    
    fname_base = f"{meta.prod_line}_{meta.sn}_{meta.mode}_{time_part}"
    print(path_base)
    path_base +=fname_base

    print(f"Saving sensor metadata to: {path_base}.json")
    source.write_metadata(f"{path_base}.json")
    
    #source.write_metadata(f"{fname_base}.json")


    print(f"Writing to: {path_base}.pcap (Ctrl-C to stop early)")
    source_it = time_limited(12*3600, source)
    n_packets = pcap.record(source_it, f"{path_base}.pcap")

    print(f"Captured {n_packets} packets")
    
    

