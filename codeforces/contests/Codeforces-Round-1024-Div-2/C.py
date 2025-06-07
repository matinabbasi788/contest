from collections import deque

t = int(input())
for _ in range(t):
    n = int(input())
    grid = [[-1] * n for _ in range(n)]
    used = [[False] * n for _ in range(n)]

    nums = list(range(n * n - 1, -1, -1))  # از بزرگ به کوچک
    idx = 0

    # BFS-like fill from center
    cx, cy = n // 2, n // 2
    q = deque()
    q.append((cx, cy))
    used[cx][cy] = True

    while q:
        x, y = q.popleft()
        grid[x][y] = nums[idx]
        idx += 1

        for dx, dy in [(-1,0),(1,0),(0,-1),(0,1)]:
            nx, ny = x + dx, y + dy
            if 0 <= nx < n and 0 <= ny < n and not used[nx][ny]:
                used[nx][ny] = True
                q.append((nx, ny))

    for row in grid:
        print(" ".join(map(str, row)))

