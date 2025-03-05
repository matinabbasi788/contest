def is_prime(n):
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True


a = []
c = 2
while len(a) < 100003:
    if is_prime(c):
        a.append(c)
    c += 1
print(a[10000])
