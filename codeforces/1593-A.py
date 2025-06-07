for _ in range(int(input())):
    a = list(map(int, input().split()))
    m = max(a)
    if a.count(m) == 1:
        for i in a:
            if i == m:
                print(0, end=' ')
            else:
                print(m - i + 1, end=' ')
    else:
        for i in a:
            if i == m:
                print(1, end=' ')
            else:
                print(m - i + 1, end=' ')
    print()
