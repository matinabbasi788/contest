# from math import gcd
#
#
# def coprimes(start, end):
#     coprime = []
#     for m in range(start, end + 1):
#         for n in range(1, m):
#             if (m % 2 != n % 2) and gcd(m, n) == 1:
#                 coprime.append((m, n))
#     return coprime
#
#
# a = coprimes(2, 110)
#
# for m, n in a:
#     print(m, n)
#     a = (m ** 2) - (n ** 2)
#     b = 2 * m * n
#     c = (m ** 2) + (n ** 2)
#     if a + b + c == 1000:
#         print(a, b, c)
#         print(a + b + c)
#         print(a * b * c)
#         break

# Python
# This may not be the efficient solution, but it is clean

# for a in range(1, 997):
#     for b in range(a+1, 998):  # b starts from a+1 to ensure that a < b
#         for c in range(b+1, 999):  # c starts from b+1 to ensure that b < c
#             if a+b+c == 1000 and a**2+b**2 == c**2:
#                 print(a*b*c)


from math import sqrt
for a in range(1, 1000):
    for b in range(1, 1000):
        if sqrt(a**2 + b**2) == int(sqrt(a**2 + b**2)):
            f = sqrt(a**2 + b**2)
            if a+b+f == 1000:
                print(a, b, f)
                print(a*b*f)
