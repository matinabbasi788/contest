import heapq


def dijkstra(n, adj):
    INF = float('inf')
    dist = [INF] * (n + 1)
    parent = [-1] * (n + 1)
    dist[1] = 0
    pq = [(0, 1)]

    while pq:
        d, u = heapq.heappop(pq)
        if d > dist[u]:
            continue

        for w, v in adj[u]:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                parent[v] = u
                heapq.heappush(pq, (dist[v], v))

    if dist[n] == INF:
        return [-1]

    path = []
    v = n
    while v != -1:
        path.append(v)
        v = parent[v]
    return path[::-1]


n, m = map(int, input().split())
adj = {i: [] for i in range(1, n + 1)}

for _ in range(m):
    u, v, w = map(int, input().split())
    adj[u].append((w, v))
    adj[v].append((w, u))

print(*dijkstra(n, adj))
