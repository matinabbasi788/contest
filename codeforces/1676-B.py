for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    d = min(arr)
    ans = 0
    for i in arr:
        ans += i - d
    print(ans)
