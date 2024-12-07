

n = int(input())
a = list(map(int, input().split()))
from collections import Counter

count = Counter(a)
taxis = count[4]  # Each group of 4 needs a separate taxi

# Pair groups of 3 with groups of 1
pair_3_and_1 = min(count[3], count[1])
taxis += pair_3_and_1
count[3] -= pair_3_and_1
count[1] -= pair_3_and_1

# Remaining groups of 3 each need a separate taxi
taxis += count[3]

# Pair groups of 2 with each other
taxis += count[2] // 2
count[2] %= 2

# If there's one group of 2 left, try to pair with up to two groups of 1
if count[2] > 0:
    taxis += 1
    count[1] -= min(2, count[1])

# Remaining groups of 1 can share taxis, four per taxi
if count[1] > 0:
    taxis += (count[1] + 3) // 4  # Ceiling division

print(taxis)