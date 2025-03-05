for _ in range(int(input())):
    m, a, b, c = map(int, input().split())
    ans = 0
    ans += min(m, a)
    ans += min(m, b)
    ans += min(m*2 - ans, c)
    print(ans)
