primes = []


def prime(n):
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True


for i in range(1, 10000):
    if prime(i):
        primes.append(i)

for i in sorted(primes, reverse=True):
    if 600851475143 % i == 0:
        print(i)
        break
