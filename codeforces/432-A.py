n, k = map(int, input().split())
array = sorted(list(map(int, input().split())))
ans = 0
for i in array:
    if i + k <= 5:
        ans += 1
print(ans//3)
