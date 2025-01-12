t = int(input())
for _ in range(t):
    n, k = map(int,  input().split())
    ans = 0
    for i in range(k):
        a = list(map(int, input().split()))
        if a[0] <= n:
            ans += a[1]
    print(ans)