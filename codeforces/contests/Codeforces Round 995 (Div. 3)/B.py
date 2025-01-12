for _ in range(int(input())):
    n, a, b, c = map(int, input().split())
    ans = (n // (a + b + c)) * 3
    n = n % (a + b + c)
    i = 0
    while n > 0:
        if i % 3 == 0:
            ans += 1
            n -= a
        elif i % 3 == 1:
            ans +=1
            n -= b
        elif i % 3 == 2:
            ans +=1
            n -= c
        i += 1
    print(ans)
