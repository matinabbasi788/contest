import sys

def solve():
    t = int(sys.stdin.readline())
    for _ in range(t):
        n = int(sys.stdin.readline())
        if n == 1:
            print(1)
        elif n % 2 == 0:
            print(-1)
        else:
            res = []
            left = 1
            right = n - 1
            turn = True  # True for right, False for left
            res.append(n)
            for i in range(1, n):
                if i % 2 == 1:
                    res.append(left)
                    left += 1
                else:
                    res.append(right)
                    right -= 1
            print(' '.join(map(str, res)))

solve()
