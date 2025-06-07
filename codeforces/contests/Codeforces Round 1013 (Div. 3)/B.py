import sys

def solve():
    t = int(sys.stdin.readline())
    for _ in range(t):
        n, x = map(int, sys.stdin.readline().split())
        a = list(map(int, sys.stdin.readline().split()))
        a.sort()
        res = 0
        i = n - 1
        count = 0
        while i >= 0:
            count += 1
            if a[i] * count >= x:
                res += 1
                count = 0
            i -= 1
        print(res)

solve()
