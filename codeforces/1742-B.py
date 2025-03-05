for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    a = []
    for i in arr:
        if i not in a:
            a.append(i)
        else:
            print("NO")
            break
    else:
        print("YES")
