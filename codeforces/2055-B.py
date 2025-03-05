t = int(input())
for _ in range(t):
    N = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    bad = -1
    margin = 1e9
    need = 0
    reject = False
    for i in range(N):
        if a[i] < b[i]:
            if bad != -1:
                reject = True
            bad = i
            need = b[i] - a[i]
        else:
            margin = min(margin, a[i] - b[i])
    if reject:
        print("NO")
        continue
    else:
        print("YES" if margin >= need else "NO")
