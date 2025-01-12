for _ in range(int(input())):
    n, x = map(int, input().split())
    ans = 1
    cnt = 3
    while cnt <= n:
        cnt += x
        ans += 1
    print(ans)