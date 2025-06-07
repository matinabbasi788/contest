for _ in range(int(input())):
    n, m, p, q = map(int, input().split())
    a = n / p
    b = n % p
    if b == 0:
        if m == a * q:
            print("YES")
        else:
            print("NO")
    else:
        print("YES")
