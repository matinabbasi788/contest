n, t = map(int, input().split())
a = list(map(int, input().split()))
visted = []
visted.append(a[0] + 1)
v = a[0] + 1
while v < n:
    visted.append(v)
    v = v + a[v-1]
visted.append(v)
print('YES' if t in visted else 'NO')
