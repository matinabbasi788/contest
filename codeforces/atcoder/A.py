for _ in range(int(input())):
    h, w = map(int, input().split())
    s = input()
    ans = 1
    for i in s:
        if i == '?':
            ans += 3
        else:
            ans += 1
    print(min(ans, h*w))
