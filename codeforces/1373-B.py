def solve(s: list):
    flg = False
    i = 1
    if len(s) == 1:
        return flg
    while s:
        if s[i-1] != s[i]:
            flg = not flg
            s.pop(i)
            s.pop(i-1)
            i = 1
        else:
            i += 1
        if i == len(s):
            return flg
    return flg


for _ in range(int(input())):
    s = list(input())
    if solve(s):
        print("DA")
    else:
        print("NET")

