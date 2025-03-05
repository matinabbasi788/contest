import math

t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    # gcd_ab = math.gcd(a, b)
    # lcm_ab = (a * b) // gcd_ab
    print(math.lcm(a, b))
