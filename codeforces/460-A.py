n, m = map(int, input().split())
ans = 0
while n:
    n -= 1
    ans += 1
    if ans % m == 0:
        n += 1
print(ans)
