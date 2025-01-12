n = int(input())
arr = list(map(int, input().split()))
minimum = arr[0]
maximum = arr[0]
ans = 0
for i in arr[1:]:
    if i > maximum or i < minimum:
        ans += 1
        maximum = max(maximum, i)
        minimum = min(minimum, i)
print(ans)