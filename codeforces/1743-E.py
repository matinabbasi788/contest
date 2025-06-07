from math import inf


p1, t1 = map(int, input().split())
p2, t2 = map(int, input().split())
h, s = map(int, input().split())

ans = inf
dp = [inf] * (h + 1)
dp[0] = 0
ts = [t1, t2]
ps = [p1, p2]

for i in range(h):
    for j in range(1, h - i + 1):
        for k in range(2):
            ni = min(h, i + j * (ps[k] - s) + (j * ts[k] // ts[k ^ 1]) * (ps[k ^ 1] - s))
            if ni == h:
                ans = min(ans, dp[i] + j * ts[k])
            if j * ts[k] >= ts[k ^ 1]:
                ni = min(h, i + (j - 1) * (ps[k] - s) + ((j * ts[k] // ts[k ^ 1]) - 1) * (ps[k ^ 1] - s) + (ps[0] + ps[1] - s))
                dp[ni] = min(dp[ni], dp[i] + j * ts[k])

ans = min(ans, dp[h])
print(ans)
