t = int(input())
matrix = []
for i in range(t):
    n, m = map(int, input().split())
    for i in range(n):
        matrix.append(list(input().split()))