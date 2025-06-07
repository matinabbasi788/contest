n = int(input())
h = list(map(int, input().split()))
x = list(map(int, input().split()))
ans = 1
for i in range(1, n-1):
    if h[i] < x[i]-x[i-1]:
        ans += 1
print(ans)
