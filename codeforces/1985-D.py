def solve(n: int, m: int):
    grid = []
    for i in range(n):
        grid.append(input())
    pos = []
    for i in range(n):
        for j in range(m):
            if grid[i][j] == '#':
                pos.append((i+1, j+1))
    return ' '.join(map(str, pos[len(pos)//2]))


for _ in range(int(input())):
    n, m = map(int, input().split())
    print(solve(n, m))
