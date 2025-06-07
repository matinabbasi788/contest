for _ in range(int(input())):
    a = []
    s = input()
    flg = False
    a = list(s)
    for i in range(len(a)):
        if a[i] != a[0]:
            a[i], a[0] = a[0], a[i]
            b = ''.join(a)
            if s != b:
                flg = True
    if flg:
        print("YES")
        print(b)
    else:
        print("NO")
