from collections import OrderedDict


for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = OrderedDict.fromkeys(a)
    print(*b.keys())
