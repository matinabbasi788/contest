from math import gcd


ab, ac, bd = map(int, input().split())
x = ab * ac
y = bd - ac
z = gcd(x, y)
x //= z
y //= z
print(f"{x}/{y}")
