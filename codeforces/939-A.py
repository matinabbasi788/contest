graph = []
n = int(input())
arr = list(map(int, input().split()))
for i in range(n):
    graph.append(arr[i] - 1)
for i in range(n):
    x = i
    y = graph[x]
    z = graph[y]
    if graph[z] == x:
        print("YES")
        break
else:
    print("NO")
