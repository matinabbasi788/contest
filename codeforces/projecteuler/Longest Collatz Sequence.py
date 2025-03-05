def f(n):
    ans = 1
    while n != 1:
        if n % 2 == 0:
            n /= 2
        else:
            n = 3 * n + 1
        ans += 1
    return ans


a = []
for i in range(100_000, 1_000_000):
    a.append((f(i), i))
print(max(a))
