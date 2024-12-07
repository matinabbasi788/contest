n, k = map(int, input().split())
ans = 0
array = list(map(int, input().split()))
for i in array:
    if i >= array[k-1] and i > 0:
        ans += 1
print(ans)