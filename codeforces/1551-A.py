for _ in range(int(input())):
    n = int(input())
    c1 = n // 3
    c2 = n // 3
    if n - (c1 + c2 * 2) == 2:
        c2 += 1
    elif n - (c1 + c2 * 2) == 1:
        c1 += 1
    print(c1, c2)
