n, m = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()
best = float('inf')
for k in range(0, m - n + 1):
    best = min(best, arr[k+n-1] - arr[k])
print(best)
