for _ in range(int(input())):
    ans = [0]
    n = int(input())
    a = list(map(int, input().split()))
    b = []
    b.append(a[0])
    for i in range(1, n):
        if a[i] not in b:
            b.append(a[i])
        b.sort()
        x = b[-1]
        y = b[-2]
        ans.append(x % y + y % x)
    print(ans)
