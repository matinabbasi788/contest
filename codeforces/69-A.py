n = int(input())
x, y, z = [], [], []
for i in range(n):
    temp = list(map(int, input().split()))
    x.append(temp[0])
    y.append(temp[1])
    z.append(temp[2])
if sum(x) == 0 and sum(y) == 0 and sum(z) == 0:
    print("YES")
else:
    print("NO")
