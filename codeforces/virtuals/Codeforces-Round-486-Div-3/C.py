n = int(input())
a = []
for i in range(n):
    t = int(input())
    a.append(list(map(int, input().split())))
s = []
for i in a:
    s.append(sum(i))
for i in range(len(a)):
    for j in range(i+1, len(a)):
        for k in range(min(len(a[i]), len(a[j]))):
            if s[i] - a[i][k] == s[j] - a[j][k]:
                print("YES")
                print(i+1, a[i].index(a[i][k])+1)
                print(j+1, a[j].index(a[j][k])+1)
                exit()
print("NO")
