n = int(input())
a = list(map(int, input().split()))
dp = {}
ans = 0
curr = 0
arr_ans = []
for i in range(n):
    dp[a[i]] = max(dp.get(a[i], 1), dp.get(a[i] - 1, 0) + 1)

    if dp[a[i]] > ans:
        ans = dp[a[i]]
        curr = a[i]
print(ans)
for i in range(n-1, -1, -1):
    if a[i] == curr:
        curr -= 1
        arr_ans.append(i+1)
arr_ans.reverse()
print(' '.join(list(map(str, arr_ans))))
