t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    flg = True
    for i in range(1, n):
        if abs(a[i-1] - a[i]) not in (5, 7):
            flg = False
    if flg:
        print("YES")
    else:
        print("NO")
        