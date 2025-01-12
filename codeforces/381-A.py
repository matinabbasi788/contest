n = int(input())
arr = list(map(int, input().split()))
s = d = 0
i = 0
while arr:
    if i % 2 == 0:
        if arr[-1] >= arr[0]:
            s += arr.pop()
        else:
            s += arr.pop(0)
    else:
        if arr[-1] >= arr[0]:
            d += arr.pop()
        else:
            d += arr.pop(0)
    i += 1
print(s, d)
