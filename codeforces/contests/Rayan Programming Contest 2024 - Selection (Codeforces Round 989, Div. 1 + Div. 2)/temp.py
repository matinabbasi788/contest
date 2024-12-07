import math

t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    gcd_ab = math.gcd(a, b)  # بزرگترین مقسوم علیه مشترک
    lcm_ab = (a * b) // gcd_ab  # کمترین مضرب مشترک
    print(lcm_ab)