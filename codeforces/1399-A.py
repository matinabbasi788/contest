for _ in range(int(input())):
    n = int(input())
    a = sorted(list(map(int, input().split())))
    for i in range(n):
        if len(a) == 1:
            print("YES")
            break
        elif abs(a[0] - a[1]) > 1:
            print("NO")
            break
        a.pop(0)
        
