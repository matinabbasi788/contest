for i in range(int(input())):
    a = sorted(list(map(int, input().split())))
    if a[1] + a[2] >= 10:
        print("YES")
    else:
        print("NO")
