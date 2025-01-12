best, _sum = 0, 0
array = list(map(int, input().split()))
for i in array:
    _sum = max(i, _sum + i)
    best = max(best, _sum)
print(best)
