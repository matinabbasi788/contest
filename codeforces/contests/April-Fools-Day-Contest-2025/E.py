n, p, k = map(int, input().split())
a = list(map(int, input().split()))
ans = 0
mod = k % p
for i in range(n):
    for j in range(i+1, n):
        if (a[i] ^ a[j]) * ((a[i] ** 2) ^ (a[j] ** 2)) == mod:
            ans += 1

print(ans)

