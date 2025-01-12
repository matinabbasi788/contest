a = sorted(list(map(int, input().split())))
ans = 0
for i in range(len(a) - 1):
    m = float('inf')
    for j in range(i+1, len(a)):
        m = min(abs(a[i] - a[j]), m)
    ans += m
print(ans)