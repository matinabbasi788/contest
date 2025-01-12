n, m = map(int, input().split())
flg = True
while True:
    n += 1
    flg = True
    if n % 2 == 0:
        flg = False
    
    for i in range(3, n):
        if n % i == 0:
            flg = False
            break
    if n > m:
        print("NO")
        break
    if flg == True and m == n:
        print("YES")
        break
    elif flg == True and m != n:
        print("NO")
        break
