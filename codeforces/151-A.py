from math import floor


n, k, l, c, d, p, nl, np = map(int, input().split())
print(min(floor(k*l/nl), c*d, floor(p/np)) // n)
