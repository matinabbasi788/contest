from math import ceil
n, m, a = map(int, input().split())
ans = ceil(n/a) * ceil(m/a)
print(ans)