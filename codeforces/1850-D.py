def solve(n, k, a):
    a.sort()
    ans = 1
    best = 1
    for i in range(1, n):
        if a[i] - a[i-1] > k:
            ans = 1
        else:
            ans += 1
        best = max(ans, best)
    return n - best


for _ in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    print(solve(n, k, a))
