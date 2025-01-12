k, r = map(int, input().split())
for i in range(1, 10):
    if (k * i) % 10 in (r, 0):
        print(i)
        break
