import math

def sign(x):
    eps = 1e-9
    return (x > eps) - (x < -eps)

def calc(a, b, c):
    m = (b[1] - a[1]) / (b[0] - a[0])
    y = m * (c[0] - a[0]) + a[1]
    return abs(y - c[1])

def solve():
    n = int(input())
    tp = [tuple(map(float, input().split())) for _ in range(n)]
    delta = float(input())
    
    dp = [2000] * n
    dp[0] = 1
    
    for i in range(1, n):
        for j in range(i):
            if dp[j] + 1 < dp[i]:
                f = True
                for k in range(j + 1, i):
                    if sign(calc(tp[i], tp[j], tp[k]) - delta) > 0:
                        f = False
                        break
                if f:
                    dp[i] = dp[j] + 1
    
    print(dp[n - 1])

def main():
    t = 1
    # t = int(input())  # Uncomment if there are multiple test cases
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
