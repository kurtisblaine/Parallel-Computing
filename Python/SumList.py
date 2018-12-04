#!/usr/bin/env python3

from threading import Lock, Thread
import time
import random
NUMT = 4 # Number of threads
lock = Lock()
gSum = 0 # Global Sum
print("Starting!")
randList = [ ]
def start(x):
    global gSum
    for count, n in enumerate(randList):
        if(count % NUMT == x):
            lock.acquire()
            gSum += n
            lock.release()

#Generate List   
for x in range(10):
    randList.append(random.randint(0,1000))
#Generate Threads
tid = [ ]
for i in range(NUMT):
    t = Thread(target=start, args=(i,))
    tid.append(t)
    t.start()
#Join Threads
for thread in tid:
    thread.join()
for n in randList:
    print(n)
print("Global sum: ", gSum)
print("\nDone!")
