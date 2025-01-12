for _ in range(int(input())):
    temp = int(input())
    while True:
        if '33' in str(temp) and '33' != str(temp):
            temp = str(temp)
            temp = int(temp[:temp.index('33')] + temp[temp.index('33') + 2:])
        else:
            temp -= 33
        if temp == '':
            temp = 0
        if temp == 0:
            print("YES")
            break
        elif temp < 33:
            print("NO")
            break
