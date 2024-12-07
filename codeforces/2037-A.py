from math import floor

t = int(input())
for _ in range(t):
    v = []
    ans = 0
    n = int(input())
    a = list(map(int, input().split()))
    for i in a:
        if i not in v:
            ans += floor(a.count(i) / 2)
            v.append(i)
    print(ans)