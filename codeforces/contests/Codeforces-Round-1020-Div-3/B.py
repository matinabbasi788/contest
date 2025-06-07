for _ in range(int(input())):
    n, x = map(int, input().split())
    ans = []
    for i in range(n):
        if i != x:
            ans.append(i)
    ans.append(x)
    print(*ans)
