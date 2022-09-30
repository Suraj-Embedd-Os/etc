import matplotlib.pyplot as plt

plt.ion()
fig = plt.figure(figsize=(16,8))
axes = fig.add_subplot(111)
data_plot=plt.plot(0,0)
line, = axes.plot([],[])
x = []
y = []

while True:
    for i in in open('sample.txt', 'r'):
        x.append(i) # range(i)
        y.append(i) # = range(i)
        line.set_ydata(y)
        line.set_xdata(x)
        if len(y)>0:
            axes.set_ylim(min(y),max(y)+1) # +1 to avoid singular transformation warning
            axes.set_xlim(min(x),max(x)+1)
        plt.title(str(i))
        plt.draw()
        plt.pause(0.1)
        #plt.show(block=True)
        
   
   
 import matplotlib.pyplot as plt

import matplotlib.pyplot as plt

x = []
y = []
for line in open('sample.txt', 'r'):
	lines = [i for i in line.split()]
	x.append(lines[0])
	y.append(int(lines[1]))
	
plt.title("Students Marks")
plt.xlabel('Roll Number')
plt.ylabel('Marks')
plt.yticks(y)
plt.plot(x, y, marker = 'o', c = 'g')

plt.show()

