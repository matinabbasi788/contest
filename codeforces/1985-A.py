for _ in range(int(input())):
    a, b = input().split()
    c, d = '', ''
    c = a[0] + b[1:]
    d = b[0] + a[1:]
    print(d, c)
