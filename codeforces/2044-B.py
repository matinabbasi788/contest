for _ in range(int(input())):
    a = input()
    b = ''
    for i in a:
        if i == 'q':
            b += 'p'
        elif i == 'p':
            b += 'q'
        else:
            b += i
    print(b[::-1])
