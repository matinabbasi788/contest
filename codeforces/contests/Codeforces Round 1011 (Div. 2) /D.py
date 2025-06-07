def solve_kaitenzushi():
    t = int(input())

    for _ in range(t):
        n, k = map(int, input().split())
        d = list(map(int, input().split()))

        dp = [-float('inf')] * (n + 1)
        dp[0] = 0  # Base case: 0 sushi, 0 deliciousness

        for i in range(n):
            next_dp = [-float('inf')] * (n + 1)

            for r in range(n + 1):
                if dp[r] == -float('inf'):
                    continue

                next_dp[r] = max(next_dp[r], dp[r])

                if r + k <= n:
                    next_dp[r + k] = max(next_dp[r + k], dp[r] + d[i])

                if r > 0:
                    next_dp[r - 1] = max(next_dp[r - 1], dp[r])

            dp = next_dp

        print(dp[0])


solve_kaitenzushi()
