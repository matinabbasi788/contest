for _ in range(int(input())):
    x, y = map(int, input().split())
    if x == y:
        print(-1)
    else:
        print((1 << 50) - max(x, y))
