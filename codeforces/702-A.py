n = int(input())
arr = list(map(int, input().split()))
ans = 1
best = 1
for i in range(1, n):
    if arr[i-1] < arr[i]:
        ans += 1
        best = max(ans, best)
    else:
        ans = 1
print(best)
