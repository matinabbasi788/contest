for _ in range(int(input())):
    l, r = map(int, input().split())
    L, R = map(int, input().split())
    ans = min(r, R) - max(l, L) + 1
    if ans <= 0:
        print(1)
    else:
        ans += (l != L)
        ans += (r != R)
        print(ans-1)
