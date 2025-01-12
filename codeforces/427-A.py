n = int(input())
ans = 0
a = list(map(int, input().split()))
l = len(a)
for i in range(l):
    if -1 in a:
        ans += a[i]
    a[i] = 1
print(abs(ans))