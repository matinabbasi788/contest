for _ in range(int(input())):
    x = int(input())
    for i in range(x, 1, -1):
        a = x
        b = i
        c = x ^ i
        if a + b > c and a + c > b and b + c > a:
            print(b)
            break
    else:
        print(-1)
