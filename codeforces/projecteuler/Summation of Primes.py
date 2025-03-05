def is_prime(n):
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True


ans = 0
for i in range(2, 2_000_000):
    if is_prime(i):
        ans += i
print(ans)
