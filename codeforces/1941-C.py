def solve(n: int, s: str):
    ans = 0
    i = 0
    while i < n - 2:
        if n >= 5 and s[i:i+6] == "mapie":
            ans += 1
            i += 5
        elif s[i] + s[i+1] + s[i+2] in ("map", "pie"):
            ans += 1
            i += 3
        else:
            i += 1
    return ans


for _ in range(int(input())):
    n = int(input())
    s = input()
    print(solve(n, s))
