n = int(input())
l = list(map(int, input().split()))
for i in l:
    m = i ** 0.5
    if m != int(i ** 0.5):
        print("NO")
    else:
        flg = True
        if m == 2:
            print("YES")
            continue
        if m < 3:
            flg = False
        for j in range(3, i):
            if j % m == 0:
                flg = False
        if flg:
            print("YES")
            flg = True
        else:
            print("NO")
            flg = True
            