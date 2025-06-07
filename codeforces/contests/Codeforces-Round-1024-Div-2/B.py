for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    a = abs(arr[0])
    c = 0
    for i in range(1, n):
        if abs(arr[i]) < a:
            c += 1
    if c <= n//2:
        print("YES")
    else:
        print("NO")
