a = []
for i in range(4):
    a.append(input())
for i in range(3):
    for j in range(3):
        b = [a[i][j], a[i][j+1], a[i+1][j+1], a[i+1][j]]
        if a[i][j] == a[i][j+1] and a[i][j] == a[i+1][j+1] and a[i][j] == a[i+1][j]:
            print("YES")
            exit()
        elif (b.count('#') == 3 and b.count('.') == 1) or\
             (b.count('.') == 3 and b.count('#') == 1):
            print("YES")
            exit()
print("NO")
