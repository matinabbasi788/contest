n, l = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()
best = 0
for i in range(len(arr)):
    if arr[i] - arr[i-1] > best:
        best = arr[i] - arr[i-1]
print(f"{max(max(arr[0], best/2), l - arr[-1]):.10f}")
