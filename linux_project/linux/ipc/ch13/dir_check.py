import os

path="/mnt/d/suraj/linux/ipc/ch16"
isExist = os.path.exists(path)
if isExist!=True:
	print(isExist)
else:
	print("path found")
