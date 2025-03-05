n, t = map(int, input().split())  # n number of books, t free time

# a[i] shows number of minutes need to read a[i] book
a = list(map(int, input().split()))
r = sm = ans = 0
for i in range(n):
    while r < n and sm + a[r] <= t:
        sm += a[r]
        r += 1
    ans = max(ans, r - i)
    sm -= a[i]
print(ans)
