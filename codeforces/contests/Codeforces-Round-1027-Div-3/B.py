for _ in range(int(input())):
    n, k = map(int, input().split())
    s = input()
    c0 = s.count('0')
    c1 = n - c0
    m = n//2
    x = m - k
    if (0 <= x and x <= m) and (c0 >= x and c1 >= x) and (((c0-x) % 2) == 0) and (((c1-x) % 2) == 0):
        print("YES")
    else:
        print("NO")
