n = int(input())
arr = input()
ans = 0
i = 0
while i < len(arr):
    if arr[i:i+2] in ("RU", "UR"):
        ans += 1
        i += 2
    else:
        ans += 1
        i += 1
print(ans)
