import sys


sys.setrecursionlimit(1000000)


coins = [1, 3, 4]
memo = [-1] * 1000000


def solve(x):
    if x < 0:
        return float('inf')
    if x == 0:
        return 0
    if memo[x] != -1:
        return memo[x]
    best = float('inf')
    for c in coins:
        best = min(best, solve(x - c) + 1)
    memo[x] = best
    return best


print(solve(100000))
