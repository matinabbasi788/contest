for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    ans = float('inf')
    for i in range(n):
        j = i
        while j+1 < n and a[j+1] == a[i]:
            j += 1
        v = a[i]
        cost = v * (i + (n-1-j))
        ans = min(ans, cost)
        i = j+1
    print(ans)
