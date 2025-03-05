from collections import Counter


def solve(n: int, k: int, s: str):
    c = Counter(s)
    odds = 0
    while True:
        for i in c:
            if c[i] % 2 == 1:
                odds += 1
        if odds > k + 1:
            return "NO"
        else:
            return "YES"


for _ in range(int(input())):
    n, k = map(int, input().split())
    s = input()
    print(solve(n, k, s))
