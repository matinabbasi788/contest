ans = 0

fib = [0] * 1001
fib[0] = 1
fib[1] = 2
for i in range(1000):
    fib[i+1] = fib[i] + fib[i-1]
for i in fib:
    if i % 2 == 1 and i < 4_000_000:
        ans += i
print(ans)
