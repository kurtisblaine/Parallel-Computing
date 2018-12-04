#!/usr/bin/env python3

import threading
import time
import random

print("Starting!")
def hello(n):
    time.sleep(random.randint(1,3))
    print("[{0}] Hello!".format(n))

tid = [ ]
for i in range(6):
    t = threading.Thread(target=hello, args=(i,))
    tid.append(t)
    t.start()

for thread in tid:
    thread.join()

print("\nDone!")
