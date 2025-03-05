for _ in range(int(input())):
    n = int(input())
    s = list(map(int, input().split()))
    s.sort()
    ans = float('inf')
    best = float('inf')
    for i in range(n):
        ans = abs(s[i-1] - s[i])
        best = min(best, ans)
    print(best)
