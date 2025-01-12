

n = int(input())
print(f"furmula: {int((1 / sqrt(5)) * ((1 + sqrt(5)) / 2) ** n - (1 / sqrt(5) * ((1 - sqrt(5)) / 2) ** n))}")

def fib(n):
    if n <= 2:
        return 1
    return fib(n-1) + fib(n-2)

print(f"recursion: {fib(n)}")

# [1, 1, 2, 3, 5, 8, 13, 21]
#  1, 2, 3, 4, 5, 6, 7,  8

