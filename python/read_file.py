with open('the-zen-of-python.txt') as f:
    while True:
        line = f.readline()
        if not line: 
            break
        print(line) 