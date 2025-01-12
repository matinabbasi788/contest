t = int(input())
for _ in range(t):
    *a, n = map(int, input().split())
    a.sort()
    n -= 2 * a[2] - a[1] - a[0]
    if n < 0 or n % 3 != 0:
        print("NO")
    else:
        print("YES")