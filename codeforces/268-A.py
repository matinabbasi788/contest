n = int(input())
ans = 0
h = []
a = []
for i in range(n):
    temp = list(map(int, input().split()))
    h.append(temp[0])
    a.append(temp[1])
for i in h:
    for j in a:
        if i == j:
            ans += 1
print(ans)