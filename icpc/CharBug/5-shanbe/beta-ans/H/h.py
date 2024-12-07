def solve():
    n, m = map(int, input().split())
    
    g = [input() for _ in range(n)]
    
    dp = [[0] * m for _ in range(n)]
    ans = 0
    
    for i in range(n):
        for j in range(m):
            if i != 0:
                dp[i][j] = dp[i - 1][j]
                if j - 1 >= 0:
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1])
                if j + 1 < m:
                    dp[i][j] = max(dp[i][j], dp[i - 1][j + 1])
                    
            if g[i][j] == 'B':
                dp[i][j] += 1
            if g[i][j] == 'W':
                ans = max(ans, dp[i][j])
                dp[i][j] = 0
    
    print(ans)

def main():
    t = 1  # Change if multiple test cases are needed
    # t = int(input())  # Uncomment if input for t is required
    
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
