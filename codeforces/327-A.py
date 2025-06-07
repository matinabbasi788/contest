n = int(input())
arr = list(map(int, input().split()))

ones = arr.count(1)
ans = 0
for i in arr:
    for j in arr:
        ans = ones
        if i == 1:
            ans -= 1
        if i == 0:
            ans += 1
    print(ans)
