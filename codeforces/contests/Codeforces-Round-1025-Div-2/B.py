def can(x):
    if x <= 1:
        return 0
    return (x-1).bit_length()


for _ in range(int(input())):
    n, m, a, b = map(int, input().split())
    da = min(a, n-a+1)
    db = min(b, m-b+1)
    ch = 1 + can(m) + can(da)
    cv = 1 + can(n) + can(db)
    print(min(ch, cv))
