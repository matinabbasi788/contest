a = []
for i in range(4):
    a.append(input())
for i in range(4):
    for j in range(4):
        if j >= 1:
            if a[i][j] == '#' and a[i][j-1] == '#' and a[i+1][j-1] == '.' and a[i+1][j] == '#':
                print("YES")
                exit()
        if i >= 1:
            if a[i][j] == '#' and a[i-1][j] == '#' and a[i-1][j+1] == '.' and a[i][j+1] == '#':
                print("YES")
                exit()
print("NO")
