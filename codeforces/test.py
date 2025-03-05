import math

def solve():
    n = int(input())
    if n <= 4:
        print(0)
        return

    t = n
    n = n // 5

    dp = [0] * (n + 1)

    if len(dp) > 1:
        dp[1] = 1

    res = 1

    for i in range(10, t + 1, 5):
        # Check indices before accessing
        if i // 5 >= len(dp) or i // 25 >= len(dp):
            break  # Or raise an error

        if (i // 5) % 5 == 0:
            m = i // 5
            mm = i // 25
            dp[m] = dp[mm] + 1
            res += dp[mm] + 1
        else:
            m = i // 5
            dp[m] = 1
            res += 1

    print(res)

# Run the solver
solve()