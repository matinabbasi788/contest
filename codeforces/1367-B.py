for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    e = []
    o = []
    for i in range(n):
        if i % 2 != arr[i] % 2:
            if arr[i] % 2 == 0:
                e.append(arr[i])
            else:
                o.append((arr[i]))
    if len(e) == len(o):
        print(len(o))
    else:
        print(-1)

