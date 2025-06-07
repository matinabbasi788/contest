ans = [[1, 1, 1],
       [1, 1, 1],
       [1, 1, 1]]
a = []
for _ in range(3):
    a.append(list(map(int, input().split())))


for i in range(3):
    for j in range(3):
        if i == 0 and j == 0 and a[i][j] % 2 == 1:
            ans[i][j] = 1 if ans[i][j] == 0 else 0
            ans[i][j+1] = 1 if ans[i][j+1] == 0 else 0
            ans[i+1][j] = 1 if ans[i+1][j] == 0 else 0
        elif i == 1 and j == 0 and a[i][j] % 2 == 1:
            ans[i][j] = 1 if ans[i][j] == 0 else 0
            ans[i-1][j] = 1 if ans[i-1][j] == 0 else 0
            ans[i][j+1] = 1 if ans[i][j+1] == 0 else 0
            ans[i+1][j] = 1 if ans[i+1][j] == 0 else 0
        elif i == 2 and j == 0 and a[i][j] % 2 == 1:
            ans[i][j] = 1 if ans[i][j] == 0 else 0
            ans[i-1][j] = 1 if ans[i-1][j] == 0 else 0
            ans[i][j+1] = 1 if ans[i][j+1] == 0 else 0
        elif i == 0 and j == 1 and a[i][j] % 2 == 1:
            ans[i][j] = 1 if ans[i][j] == 0 else 0
            ans[i][j-1] = 1 if ans[i][j-1] == 0 else 0
            ans[i][j+1] = 1 if ans[i][j+1] == 0 else 0
            ans[i+1][j] = 1 if ans[i+1][j] == 0 else 0
        elif i == 1 and j == 1 and a[i][j] % 2 == 1:
            ans[i][j] = 1 if ans[i][j] == 0 else 0
            ans[i][j+1] = 1 if ans[i][j+1] == 0 else 0
            ans[i][j-1] = 1 if ans[i][j-1] == 0 else 0
            ans[i+1][j] = 1 if ans[i+1][j] == 0 else 0
            ans[i-1][j] = 1 if ans[i-1][j] == 0 else 0
        elif i == 2 and j == 1 and a[i][j] % 2 == 1:
            ans[i][j] = 1 if ans[i][j] == 0 else 0
            ans[i][j+1] = 1 if ans[i][j+1] == 0 else 0
            ans[i][j-1] = 1 if ans[i][j-1] == 0 else 0
            ans[i-1][j] = 1 if ans[i-1][j] == 0 else 0
        elif i == 0 and j == 2 and a[i][j] % 2 == 1:
            ans[i][j] = 1 if ans[i][j] == 0 else 0
            ans[i+1][j] = 1 if ans[i+1][j] == 0 else 0
            ans[i][j-1] = 1 if ans[i][j-1] == 0 else 0
        elif i == 1 and j == 2 and a[i][j] % 2 == 1:
            ans[i][j] = 1 if ans[i][j] == 0 else 0
            ans[i-1][j] = 1 if ans[i-1][j] == 0 else 0
            ans[i][j-1] = 1 if ans[i][j-1] == 0 else 0
            ans[i+1][j] = 1 if ans[i+1][j] == 0 else 0
        elif i == 2 and j == 2 and a[i][j] % 2 == 1:
            ans[i][j] = 1 if ans[i][j] == 0 else 0
            ans[i-1][j] = 1 if ans[i-1][j] == 0 else 0
            ans[i][j-1] = 1 if ans[i][j-1] == 0 else 0

for i in ans:
    print(''.join(map(str, i)))
