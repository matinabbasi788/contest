def prime(n):
    for i in range(2, n):
        if n % i == 0:
            return False
    return True


primes = []
for i in range(2, 3000):
    if prime(i):
        primes.append(i)


n = int(input())
ans = 0
tans = 0
for i in range(1, n+1):
    ans = 0
    for j in primes:
        if i % j == 0:
            ans += 1
    if ans == 2:
        tans += 1
print(tans)
