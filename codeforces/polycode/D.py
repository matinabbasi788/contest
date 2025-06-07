n = int(input())
a = []
for i in range(n):
    a.append(int(input()))
b = 0
a.sort()
for i in range(1, n):
    b += min(a[0] % a[i], a[i] % a[0])
print(b)
