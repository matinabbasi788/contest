n, m = map(int, input().split())
a = {}
for _ in range(m):
    x, y = input().split()
    if len(x) > len(y):
        a[x] = y
    else:
        a[y] = x
b = list(input().split())
for i in b:
    if i not in a.keys():
        print(i, end=" ")
    else:
        print(a[i], end=" ")
