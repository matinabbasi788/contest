for _ in range(int(input())):
    a = list(map(int, input().split()))
    b = []
    b.append(a[0] + a[1])
    b.append(a[2] - a[1])
    b.append(a[3] - a[2])
    b = set(b)
    print(4 - len(b))
