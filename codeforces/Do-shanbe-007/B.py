for _ in range(int(input())):
    x = 0
    y = 0
    n = int(input())
    s = input()
    for i in s:
        if i == 'L':
            x -= 1
        elif i == 'R':
            x += 1
        elif i == 'U':
            y += 1
        else:
            y -= 1
        if x == 1 and y == 1:
            print("YES")
            break
    else:
        print("NO")
