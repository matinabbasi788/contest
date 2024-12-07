zeros = 0
ones = 0
cz = 0
co = 0
for i in input():
    if i == '0':
        cz += 1
        co = 0
    else:
        co += 1
        cz = 0
    zeros = max(zeros, cz)
    ones = max(ones, co)
if zeros >= 7 or ones >= 7:
    print("YES")
else:
    print("NO")