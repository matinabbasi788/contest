# سریال https://quera.org/problemset/10936

n, k = list(map(int, input().split()))
nums = list(map(int, input().split()))
ans = 0
cnt = 0
for i in range(0, n):
    if i == 0:
        cnt = 1
    elif nums[i-1] != nums[i]-1:
        cnt = 1
    else:
        cnt += 1
    ans = max(ans, cnt)
print(min(n, ans + k))