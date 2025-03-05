n = int(input())
a = list(map(int, input().split()))


length = [0] * n
for k in range(n):
    length[k] = 1
    for i in range(k):
        if a[i] < a[k]:
            length[k] = max(length[k], length[i] + 1)
print(length[n-1])
