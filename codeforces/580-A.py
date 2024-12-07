n = int(input())
a = list(map(int, input().split()))

ans = 0
anst = 0
a.append(0)

for i in range(n+1):
    if a[i-1] <= a[i]:
        ans += 1
        anst = max(ans, anst)
    else:
        ans = 1
print(anst)