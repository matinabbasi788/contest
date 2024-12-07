d = [1, 5, 10, 20, 100]
n = int(input())
ans = 0
for i in d[::-1]:
    while n >= i:
        n -= i
        ans += 1
print(ans)