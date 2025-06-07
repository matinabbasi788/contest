def prime(n):
    if n == 1:
        return False
    if n == 2:
        return True
    for i in range(2, n):
        if n % i == 0:
            return False 
    return True

a = int(input())
b = int(input())
for i in range(a, b+1):
    if prime(i):
        print(i)
