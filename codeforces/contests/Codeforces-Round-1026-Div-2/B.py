for _ in range(int(input())):
    s = input()
    balance = 0
    flg = False
    for i in range(len(s)-1):
        if s[i] == '(':
            balance += 1
        else:
            balance -= 1
        if balance == 0:
            flg = True
            break
    if flg:
        print("YES")
    else:
        print("NO")
