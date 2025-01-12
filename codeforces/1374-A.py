for _ in range(int(input())):
    x, y, n = map(int, input().split())
    if n % x == y:
        print(n)
    else:
        a = n - (n % x) + y
        b = a - x
        if a > n:
            print(b)
        else:
            print(a)
