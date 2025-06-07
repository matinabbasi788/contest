for _ in range(int(input())):
    n, m = map(int, input().split())
    x = input()
    t = input()
    ans = 0
    while len(x) <= n * m * 2:
        if t in x:
            print(ans)
            break
        ans += 1
        x = x + x
    else:
        print(-1)
