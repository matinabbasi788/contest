n, k = map(int, input().split())

odd_count = (n + 1) // 2

if k <= odd_count:
    result = 2 * k - 1
else:
    result = 2 * (k - odd_count)

print(result)