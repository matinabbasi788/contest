from bisect import bisect_right


for _ in range(int(input())):
    n, q = map(int, input().split())
    a = list(map(int, input().split()))
    q = list(map(int, input().split()))
    c = [0]
    cmax = [a[0]]
    for i in range(1, n):
        cmax.append(max(cmax[i-1], a[i]))
    t = 0
    for i in a:
        t += i
        c.append(t)
    for i in q:
        print(c[bisect_right(cmax, i)], end=' ')
    print()
