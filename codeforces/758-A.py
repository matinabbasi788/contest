n = int(input())
arr = sorted(list(map(int, input().split())))
ans = 0
for i in range(len(arr) - 1):
    ans += arr[-1] - arr[i]
print(ans)

