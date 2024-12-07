matrix = []
ans = [
    [4, 3, 2, 3, 4],
    [3, 2, 1, 2, 3],
    [2, 1, 0, 1, 2],
    [3, 2, 1, 2, 3],
    [4, 3, 2, 3, 4]
]
for i in range(5):
    matrix.append(list(map(int, input().split())))
for i in range(len(matrix)):
    for j in range(len(matrix)):
        if matrix[i][j] == 1:
            print(ans[i][j])