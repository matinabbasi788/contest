n = int(input())
arr = list(map(int, input().split()))
m = 0
b = 0
for i in range(len(arr)):
    for j in range(i, len(arr)):
        m = arr[:i].count(1) + arr[i:j].count(0) + arr[j:].count(1)
        b = max(m, b)
for i in arr:
    if i != 1:
        print(b)
        break
else:
    print(b - 1)