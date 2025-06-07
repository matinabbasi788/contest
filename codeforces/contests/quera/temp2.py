n, l = map(int, input().split())

ans = 0
for i in range(n):
    n, r, g = map(int, input().split())
    ans += n - ans
