s = input()


def solve(s):
    while s:
        if s[:3] == "144":
            s = s[3:]
        elif s[:2] == "14":
            s = s[2:]
        elif s[:1] == "1":
            s = s[1:]
        else:
            return "NO"
    return "YES"


print(solve(s))
