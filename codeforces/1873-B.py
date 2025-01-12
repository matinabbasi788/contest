for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    arr.sort()
    ans = 1
    for i in arr[1:]:
        ans *= i
    print((arr[0] + 1) * ans)
