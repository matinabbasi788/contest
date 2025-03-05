n = int(input())
a = list(map(int, input().split()))
b = [0 for i in range(100001)]
for i in a:
    b[i] += 1
dp = [0 for i in range(100001)]
dp[1] = b[1]
for i in range(2, 100001):
    dp[i] = max(dp[i-1], dp[i-2] + (i * b[i]))
print(dp[100000])
