from math import ceil


n, m, a, b = map(int, input().split())
temp = n
ans = 0
while n:
    if n >= m and b / m <= a:
        n -= m
        ans += b
    else:
        n -= 1
        ans += a
print(min(ans, ceil(temp/m) * b))