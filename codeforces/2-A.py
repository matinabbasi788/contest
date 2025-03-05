d, r = {}, []
n = int(input())
for _ in range(n):
    name, score = input().split()
    d[name] = d.get(name, 0) + int(score)
    r += [(d[name], name)]
    m = max(d.values())
print([name for v, name in r if d[name] == m and v >= m][0])
