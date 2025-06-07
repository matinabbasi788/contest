for _ in range(int(input())):
    s = input()
    s = s[::-1]
    ans = 0
    for i in range(len(s)):
        if s[i] == '0':
            ans += 1
        else:
            break
    for i in range(ans+1, len(s)):
        if s[i] != '0':
            ans += 1
    print(ans)

