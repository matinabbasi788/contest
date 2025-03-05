msg = ""

for _ in range(int(input())):
    for _ in range(8):
        t = input()
        t = t.rstrip('.')
        if t:
            msg += t[-1]
    print(msg)
    msg = ""
