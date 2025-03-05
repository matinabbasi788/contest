import sys


sys.setrecursionlimit(100000)
n = int(input())
manager = [0] * (n + 1)
for i in range(1, n+1):
    manager[i] = int(input())
max_depth = 0


def dfs(employee):
    if manager[employee] == -1:
        return 1
    return 1 + dfs(manager[employee])


for i in range(1, n+1):
    depth = dfs(i)
    if depth > max_depth:
        max_depth = depth
print(max_depth)
