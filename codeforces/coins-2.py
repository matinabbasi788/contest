coins = [1, 3, 4]
value = [0] * 1000
first = [1] * 1000
for x in range(1, 100):
    value[x] = float('inf')
    for c in coins:
        if x - c >= 0 and value[x-c]+1 < value[x]:
            value[x] = value[x-c]+1
            first[x] = c
print(value[10])
n = 10
while n > 0:
    print(first[n], end=' ')
    n -= first[n]
