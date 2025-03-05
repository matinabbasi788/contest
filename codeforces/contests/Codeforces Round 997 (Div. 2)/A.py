for _ in range(int(input())):
    n, m = map(int, input().split())
    ans = m * 4 * n
    x, y = map(int, input().split())
    for i in range(1, n):
        x, y = map(int, input().split())
        ans -= ((m - x) + (m - y)) * 2
    print(ans)
