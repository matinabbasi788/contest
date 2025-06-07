for _ in range(int(input())):
    n, m = map(int, input().split())
    s = input()
    ans = 0
    a = ['A', 'B', 'C', 'D', 'E', 'F', 'G']
    for i in a:
        if s.count(i) < m:
            ans += m - s.count(i)
    print(ans)
