for _ in range(int(input())):
    x, y = map(int, input().split())
    a, b = map(int, input().split())
    ans = 0
    if b <= a * 2:
        ans += min(x, y) * b
        ans += (max(x, y) - min(x, y)) * a
    else:
        ans += sum([x, y]) * a
    print(ans)
