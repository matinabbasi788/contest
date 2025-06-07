a = ['4', '7', '77', '44']
for i in range(2):
    for j in a:
        for k in a:
            if len(a) > 300:
                break
            if j+k not in a:
                a.append(j+k)
            if k+j not in a:
                a.append(k+j)
a = sorted(list(map(int, a)))
n = int(input())
print(a.index(n)+1)
