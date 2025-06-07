n, m = map(int, input().split())
if n < m:
    print(-1)
    exit()
a = n // 2
b = n % 2
while True:
    if (a + b) % m == 0:
        print(a+b)
        break
    a -= 1
    b += 2
