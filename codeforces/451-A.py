n, m = map(int, input().split())
if n > m:
    n, m = m, n

if n % 2 == 0:
    print("Malvika")
else:
    print("Akshat")