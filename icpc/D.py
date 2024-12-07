n, q = map(int, input().split())
s = 0
for i in range(q):
    temp = input()
    if "add" in temp:
        s += temp.split()[1]
    print(s)