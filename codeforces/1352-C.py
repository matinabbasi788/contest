from math import floor


for _ in range(int(input())):
    n, k = map(int, input().split())
    print(k + floor((k-1)/(n-1)))
