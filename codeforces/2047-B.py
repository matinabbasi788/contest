t = int(input())
while t:
    t -= 1
    n = int(input())
    s = input()
    b = list(s)
    if n == 1:
        print(s)
    else:
        for i in range(n):
            b[0] = s[i]
            if s != ''.join(b):
                print(''.join(b))
                break
        else:
            print(s)
            