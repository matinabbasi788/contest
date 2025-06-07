n, b, d = map(int, input().split())
a = list(map(int, input().split()))
ans = 0
w = 0
for i in a:
    if i <= b:
        w += i
    if w > d:
        ans += 1
        w = 0
print(ans)
