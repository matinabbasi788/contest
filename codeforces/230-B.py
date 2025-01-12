from math import sqrt


p = {}


def prime(n):
    if n in p:
        return p[n]
    if n < 2:
        return False
    for i in range(2, int(sqrt(n)) + 1):
        if n % i == 0:
            p[n] = False
            return False
    p[n] = True
    return True


n = int(input())
arr = list(map(int, input().split()))


for i in arr:
    y = int(sqrt(i))
    if prime(y) and y * y == i:
        print("YES")
    else:
        print("NO")
