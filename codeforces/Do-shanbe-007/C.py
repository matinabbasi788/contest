for _ in range(int(input())):
    n = int(input())
    s = list(input())
    while (s[0] == '0' and s[-1] == '1') or (s[0] == '1' and s[-1] == '0'):
        s.pop(0)
        s.pop()
        if not s:
            break
    print(len(s))
