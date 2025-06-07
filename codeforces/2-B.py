n = int(input())
arr = []
ans = ''
zeros = 0
for _ in range(n):
    arr.append(list(map(int, input().split())))


for i in range(n):
    for j in range(n):
        print(arr[i][j], end=' ')
    print()
