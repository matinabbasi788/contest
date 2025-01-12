import threading
from threading import Barrier

barrier = Barrier(3)

def process_a():
    while True:
        print("A", end="")
        barrier.wait()

def process_b():
    while True:
        barrier.wait() 
        print("B", end="")

def process_c():
    while True:
        barrier.wait() 
        print("C", end="")


thread_a = threading.Thread(target=process_a)
thread_b = threading.Thread(target=process_b)
thread_c = threading.Thread(target=process_c)

thread_a.start()
thread_b.start()
thread_c.start()


thread_a.join()
thread_b.join()
thread_c.join()
