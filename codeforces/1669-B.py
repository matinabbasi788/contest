from collections import Counter


for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    c = Counter(a)
    for i in c:
        if c[i] >= 3:
            print(i)
            break
    else:
        print(-1)
