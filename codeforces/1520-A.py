for _ in range(int(input())):
    n = int(input())
    string = input()
    v = []
    t = string[0]
    for i in string:
        if i in v and t != i:
            print("NO")
            break
        if i not in v:
            v.append(i)
        t = i
    else:
        print("YES")
