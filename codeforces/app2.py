n = int(input())
l = list(map(int, input().split()))

ans = 0
cnt = 0
for i in range(n):
    # if i == 0:
    #     cnt += 1
    if l[i-1] > l[i]:
        ans = max(cnt, ans)
        cnt = 0
    else:
        cnt += 1
        ans = max(cnt, ans)
print(ans)
        