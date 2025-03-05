coins = [2020, 2021]
memo = [-1] * 1000005


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


for _ in range(int(input())):
    if solve(int(input())) != float('inf'):
        print("YES")
    else:
        print("NO")
