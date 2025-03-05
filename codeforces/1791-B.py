for _ in range(int(input())):
    n = int(input())
    s = input()
    p = [0, 0]
    for i in s:
        if i == 'U':
            p[0] += 1
        elif i == 'D':
            p[0] -= 1
        elif i == 'L':
            p[1] -= 1
        elif i == 'R':
            p[1] += 1
        if p == [1, 1]:
            print("YES")
            break
    else:
        print("NO")
