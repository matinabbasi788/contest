for _ in range(int(input())):
    ans = 0
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    for i in range(len(a) - 1):
        if a[i] > b[i + 1]:
            ans += a[i] - b[i + 1]
    ans += a[-1]
    print(ans)


