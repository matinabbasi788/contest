for _ in range(int(input())):
    a = [0, 1, 0, 3, 2, 0, 2, 5]
    n = int(input())
    arr = list(map(int, input().split()))
    ans = 0
    for i in arr:
        if i in a:
            a.remove(i)
        ans += 1
        if not a:
            break
    if a:
        print(0)
    else:
        print(ans)
