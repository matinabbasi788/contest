n, k = map(int, input().split())
a = 240 - k
ans = 0
for i in range(1, n + 1):
    if i * 5 <= a and a > 0:
        ans += 1
    a -= i * 5
print(ans)