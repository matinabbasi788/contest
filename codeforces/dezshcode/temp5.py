ans = 0
p = 0
a = []
ans = 0
for _ in range(int(input())):
    y, x = input().split()
    y = int(y)
    for i in range(p, y):
        if a.count(i) == 1:
            ans += 1
        a.append(i)
    # y = int(y)
    # if x == 'R':
    #     a.append((p, p+y))
    #     p += y
    # else:
    #     a.append((p, p-y))
    #     p -= y
print(ans)
