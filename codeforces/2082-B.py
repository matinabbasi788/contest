from math import ceil, floor


for _ in range(int(input())):
    x, n, m = map(int, input().split())
    # if n > x or x == 0:
    #     print(0, 0)
    #     continue
    mx = x
    for i in range(m):
        mx = ceil(mx / 2)
        if mx == 1 or mx == 0:
            break
    for i in range(n):
        mx = floor(mx / 2)
        if mx == 0:
            break
    mn = x
    for i in range(n):
        mn = floor(mn / 2)
        if mn == 0:
            break
    for i in range(m):
        mn = ceil(mn / 2)
        if mn == 1 or mn == 0:
            break
    print(mx, mn)
