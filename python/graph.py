
import time
import sys
import matplotlib.pyplot as plt
import os, glob
path = str(sys.argv[1])
#path = './sweep_data'
x=[0]
y=[0]
count=0
plt.ion()
for filename in glob.glob(os.path.join(path, '*.txt')):
   with open(os.path.join(os.getcwd(), filename), 'r') as f:
        while True:
                line = f.readline()
                if line=='': 
                    break    
                count=count+1
                x.append(count)
                y.append(int(line))
                
                    
                #print("x=",x)
                #print("y=",y)
                # plt.gca().cla() # optionally clear axes
                plt.plot(x, y)
                plt.title('graph')
                plt.draw()
                
                if count%50==0:
                    plt.pause(0.001)
                    plt.clf()
                    plt.cla()
                    x.clear()
                    y.clear()
                   
        

#plt.show(block=True)

for filename in glob.glob(os.path.join(path, '*.txt')):
   with open(os.path.join(os.getcwd(), filename), 'r') as f:
         while True:
                line = f.readline()
                if line=='': 
                    break
                print(line)
     