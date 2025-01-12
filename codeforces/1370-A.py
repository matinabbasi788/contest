from math import gcd


# for _ in range(int(input())):
#     ans = 0
#     n = int(input())
#     for i in range(1, n+1):
#         for j in range(1, n+1):
#             temp = gcd(i, j)
#             if temp > ans and i != j:
#                 ans = temp
#     print(ans)

for _ in range(int(input())):
    n = int(input())
    print(n//2)
