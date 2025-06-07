t = int(input())
for _ in range(t):
    grid = [input().strip() for _ in range(8)]
    answer = 'B'
    for row in grid:
        if all(c == 'R' for c in row):
            answer = 'R'
            break
    else:
        for col in range(8):
            if all(grid[row][col] == 'B' for row in range(8)):
                answer = 'B'
                break
    print(answer)
