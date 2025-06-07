for _ in range(int(input())):
    n, m, k = map(int, input().split())
    b = list(map(int, input().split()))
    c = list(map(int, input().split()))
    ans = 0
    for i in b:
        for j in c:
            if i + j <= k:
                ans += 1
    print(ans)
