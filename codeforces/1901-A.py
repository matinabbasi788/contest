for _ in range(int(input())):
    n, x = map(int, input().split())
    arr = list(map(int, input().split()))
    ans = (x - arr[-1]) * 2
    for i in range(len(arr) - 1):
        if arr[i+1] - arr[i] > ans:
            ans = arr[i+1] - arr[i]
    if n == 1:
        if arr[0] > ans:
            ans = arr[0]
    print(ans)
