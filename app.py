a = int(input())
b = list(map(int, input().split(' ')))
result = 0

for i in range(len(b)):
    if b[i] != 0:
        x = i
    for j in range(i+1, len(b)):
        if b[j] != 0:
            y = j
            break
    if b[x] < b[y]:
        b[x] = 0
    else:
        b[y] = 0
for i in range(len(b)):
    if b[i] != 0:
        result = i + 1
       
print(result)