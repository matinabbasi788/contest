n = int(input())

dp = [0 for _ in range(100)]
dp[0] = 1
dp[1] = 0
for i in range(2, n+1):
    dp[i] = 2 * dp[i-2]
print(dp[n])
