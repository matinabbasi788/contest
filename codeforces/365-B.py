n, k = map(int, input().split())
arr = list(map(int, input().split()))
s = 0
m = float('inf')
ans = 0
for i in range(k):
    s += arr[i]
if s < m:
    m = s
for i in range(n - k):
    s -= arr[i]
    s += arr[i+k]
    if s < m:
        m = s
        ans = i + 1
print(ans + 1)
