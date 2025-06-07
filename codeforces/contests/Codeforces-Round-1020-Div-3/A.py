for _ in range(int(input())):
    n = int(input())
    s = input()
    ans = 0
    for i in range(n):
        t = list(s)
        if t[i] == '0':
            t[i] = '1'
        else:
            t[i] = '0'
        ans += t.count('1')
    print(ans)
