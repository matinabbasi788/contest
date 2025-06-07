def solve(n, s):
    c = 0
    best = 0
    for i in range(len(s) - 1):
        if s[i] == s[i+1]:
            c += 1
            best = max(c, best)
        else:
            c = 0
    return best


for _ in range(int(input())):
    n = int(input())
    s = input()
    print(solve(n, s) + 2)
