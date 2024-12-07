from math import ceil

n = int(input())
if n % 2 == 1:
    print(-ceil(n/2))
else:
    print(ceil(n/2))