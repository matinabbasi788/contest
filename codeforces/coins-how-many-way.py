count = [0] * 1000
count[0] = 1
coins = [1, 2, 3, 4, 5, 7, 8, 9, 10]


def solve(n):
    for x in range(1, n + 1):
        for c in coins:
            if x - c >= 0:
                count[x] += count[x-c]
    return count[n]


print(solve(100))
