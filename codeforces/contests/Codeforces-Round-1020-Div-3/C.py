for _ in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = []
    m = max(a)
    for i in range(n):
        if b[i] != -1:
            c.append(a[i] + b[i])
        else:
            c.append(a[i] + (m-a[i]))
    if len(set(c)) != 1 or max(c) > k:
        print(0)
    else:
        if b.count(-1) == n:
            print(k - m + 2)
        else:
            print(1)
