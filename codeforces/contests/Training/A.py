for _ in range(int(input())):
    l, r, d, u = map(int, input().split())
    if l == r and r == d and d == u:
        print("Yes")
    else:
        print("No")
