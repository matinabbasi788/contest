def solve(x, n, m):
    while True:
        if x <= m * 10:
            return "YES"
        x = x // 2 + 10
        n -= 1
        if n == -1:
            return "NO"


for _ in range(int(input())):
    x, n, m = map(int, input().split())
    print(solve(x, n, m))
