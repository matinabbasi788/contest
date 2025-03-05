for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    ans = 0
    best = 0
    for i in a:
        if i == 0:
            ans += 1
        else:
            ans = 0
        best = max(best, ans)
    print(best)
