def solve(a, b, c, d):
    l1 = []
    l2 = []
    for i in range(min(a, b) + 1, max(a, b)):
        l1.append(i)
    for i in range(1, 13):
        if (i not in l1) and (i not in (a, b)):
            l2.append(i)
    if (c in l1 and d in l2) or (c in l2 and d in l1):
        return "YES"
    else:
        return "NO"


for _ in range(int(input())):
    a, b, c, d = map(int, input().split())
    print(solve(a, b, c, d))
