t = int(input())
for i in range(t):
    ans = 0
    a = list(map(int, input().split()))
    for i in a[1:]:
        if a[0] < i:
            ans += 1
    print(ans)