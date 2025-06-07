ans = 0
n, m = map(int, input().split())
for i in range(0, 1001):
    for j in range(0, 1001):
        if ((i ** 2) + j == n and i + (j ** 2) == m):
            ans += 1
print(ans)
