n, m = map(int, input().split())
a = sorted(list(map(int, input().split())))
ans = 0
for i in range(m):
    if a[i] < 0:
        ans += abs(a[i])
print(ans)
