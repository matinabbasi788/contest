a, b = map(int, input().split())
ans = a
while a >= b:
    r = a % b
    a = a // b
    ans += a
    a += r
print(ans)
