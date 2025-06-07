from math import gcd


n = int(input())
ans = 0
for i in range(1, n+1):
    if gcd(i, n) == 1:
        ans += 1
print(ans)
