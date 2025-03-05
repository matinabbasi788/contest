a = "abcdefghijklmnopqrstuvwxyz"


for _ in range(int(input())):
    n = int(input())
    s = input()
    print(a.index(max(s)) + 1)
