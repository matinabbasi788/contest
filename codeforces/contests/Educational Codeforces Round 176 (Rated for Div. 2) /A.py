from math import ceil


for _ in range(int(input())):
    n, k = map(int, input().split())
    print(ceil(k/n))
