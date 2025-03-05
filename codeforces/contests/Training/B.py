def solve(n: str):
    while True:
        if '33' in n and '33' != n:
            n = n[:n.index('33')] + n[n.index('33') + 2:]
        else:
            n = str(int(n) - 33)
        if n == '':
            n = 0
        if n == 0:
            return "YES"
        if int(n) < 33:
            return "NO"


for _ in range(int(input())):
    print(solve(input()))
