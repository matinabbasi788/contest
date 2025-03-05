n = int(input())
ans = 0
while n:
    n -= int(max(str(n)))
    ans += 1
print(ans)
