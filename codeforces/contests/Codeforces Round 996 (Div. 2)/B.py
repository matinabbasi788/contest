for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    d = b[0] - a[0]
    for i in range(1, n):
        if b[i] - a[i] > -(d):
            print("NO")
            break
    else:
        print("YES")
