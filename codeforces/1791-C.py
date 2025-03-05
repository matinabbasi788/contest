for _ in range(int(input())):
    n = int(input())
    s = input()
    ans = 0
    while True:
        if len(s) == 0:
            print(0)
            break
        if s[0] == '0' and s[-1] == '1' or s[0] == '1' and s[-1] == '0':
            s = s[1:-1]
        else:
            print(len(s))
            break
