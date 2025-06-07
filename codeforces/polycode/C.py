n = int(input())
a = []
b = []
ans = 0
for i in range(n):
    x, y = map(int, input().split())
    a.append(x)
    b.append(y)
for i in range(n):
    for j in range(n):
        if a[i] == b[j]:
            ans += 1
print(ans)

