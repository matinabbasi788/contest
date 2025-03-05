n, m = map(int, input().split())
tasks = list(map(int, input().split()))
ans = 0
ans += tasks[0] - 1
for i in range(m - 1):
    if tasks[i] == tasks[i+1]:
        pass
    elif tasks[i+1] < tasks[i]:
        ans += tasks[i+1] + n - tasks[i]
    else:
        ans += tasks[i+1] - tasks[i]
print(ans)
