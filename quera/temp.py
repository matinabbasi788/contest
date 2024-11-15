import threading

x = 0

def p1():
    global x
    for i in range(5):
        temp = x
        temp = temp + 1
        x = temp

def p2():
    global x
    for i in range(5):
        temp = x
        temp = temp + 1
        x = temp

t1 = threading.Thread(name="P1", target=p1)
t2 = threading.Thread(name="P2", target=p2)

t1.start()
t2.start()

t1.join()
t2.join()
print(x)