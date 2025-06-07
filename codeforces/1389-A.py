for _ in range(int(input())):
    l, r = map(int, input().split())
    for i in range(l, r):
        if i * 2 > r:
            print(-1, -1)
            break
        else:
            print(i, i * 2)
            break
