for _ in range(int(input())):
    a, b, c, d = map(int, input().split())
    if a < d and b <= c:
        if b <= a:
            print("Gellyfish")
        else:
            print("Flower")
    elif a >= d and b <= c:
        print("Gellyfish")
    elif a < d and b >= c+1:
        print("Flower")
    else:
        if d <= c:
            print("Gellyfish")
        else:
            print("Flower")
