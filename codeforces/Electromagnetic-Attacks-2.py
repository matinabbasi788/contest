import sys

# DSU for connectivity
class DSU:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        px, py = self.find(x), self.find(y)
        if px == py:
            return
        if self.rank[px] < self.rank[py]:
            px, py = py, px
        self.parent[py] = px
        if self.rank[px] == self.rank[py]:
            self.rank[px] += 1

# Check if two segments intersect
def orientation(p, q, r):
    val = (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1])
    return 0 if val == 0 else (1 if val > 0 else 2)

def on_segment(p, q, r):
    return (min(p[0], r[0]) <= q[0] <= max(p[0], r[0]) and
            min(p[1], r[1]) <= q[1] <= max(p[1], r[1]))

def segments_intersect(p1, p2, q1, q2):
    o1 = orientation(p1, p2, q1)
    o2 = orientation(p1, p2, q2)
    o3 = orientation(q1, q2, p1)
    o4 = orientation(q1, q2, p2)
    if o1 != o2 and o3 != o4:
        return True
    if o1 == 0 and on_segment(p1, q1, p2): return True
    if o2 == 0 and on_segment(p1, q2, p2): return True
    if o3 == 0 and on_segment(q1, p1, q2): return True
    if o4 == 0 and on_segment(q1, p2, q2): return True
    return False

def solve():
    input = sys.stdin.read
    data = input().split()
    index = 0

    def get_int():
        nonlocal index
        val = int(data[index])
        index += 1
        return val

    def get_ints(n):
        nonlocal index
        vals = [int(data[index + i]) for i in range(n)]
        index += n
        return vals

    # Parse input
    n, m, k = get_int(), get_int(), get_int()
    nodes = [get_ints(2) for _ in range(n)]  # (x, y) for each node
    edges = [get_ints(2) for _ in range(m)]  # (u, v) for each edge (1-based)
    attacks = [get_ints(4) for _ in range(k)]  # (x1, y1, x2, y2) for each attack

    # Convert edges to 0-based indexing
    for i in range(m):
        edges[i][0] -= 1
        edges[i][1] -= 1

    # Coordinate compression
    x_coords = set()
    y_coords = set()
    for x, y in nodes:
        x_coords.add(x)
        y_coords.add(y)
    for x1, y1, x2, y2 in attacks:
        x_coords.add(x1)
        x_coords.add(x2)
        y_coords.add(y1)
        y_coords.add(y2)
    x_map = {x: i for i, x in enumerate(sorted(x_coords))}
    y_map = {y: i for i, y in enumerate(sorted(y_coords))}
    nodes_compressed = [(x_map[x], y_map[y]) for x, y in nodes]

    # Precompute affected edges per attack
    affected_by_attack = [set() for _ in range(k)]
    for i, (x1, y1, x2, y2) in enumerate(attacks):
        cx1, cy1 = x_map[x1], y_map[y1]
        cx2, cy2 = x_map[x2], y_map[y2]
        if cx1 > cx2: cx1, cx2 = cx2, cx1
        if cy1 > cy2: cy1, cy2 = cy2, cy1
        rect_edges = [
            ((cx1, cy1), (cx1, cy2)),  # Left
            ((cx1, cy2), (cx2, cy2)),  # Top
            ((cx2, cy2), (cx2, cy1)),  # Right
            ((cx2, cy1), (cx1, cy1))   # Bottom
        ]
        for j, (u, v) in enumerate(edges):
            p1 = nodes_compressed[u]
            p2 = nodes_compressed[v]
            for re1, re2 in rect_edges:
                if segments_intersect(p1, p2, re1, re2):
                    affected_by_attack[i].add(j)
                    break

    # Process each attack
    results = []
    for i, (x1, y1, x2, y2) in enumerate(attacks):
        dsu = DSU(n)
        removed = [False] * n
        cx1, cy1 = x_map[x1], y_map[y1]
        cx2, cy2 = x_map[x2], y_map[y2]
        if cx1 > cx2: cx1, cx2 = cx2, cx1
        if cy1 > cy2: cy1, cy2 = cy2, cy1

        # Remove nodes strictly inside
        for j in range(n):
            x, y = nodes_compressed[j]
            if cx1 < x < cx2 and cy1 < y < cy2:
                removed[j] = True

        # Union unaffected edges
        affected = affected_by_attack[i]
        for j, (u, v) in enumerate(edges):
            if j not in affected and not removed[u] and not removed[v]:
                dsu.union(u, v)

        # Check connectivity
        root = -1
        connected = True
        active_nodes = 0
        for j in range(n):
            if not removed[j]:
                active_nodes += 1
                if root == -1:
                    root = dsu.find(j)
                elif dsu.find(j) != root:
                    connected = False
                    break
        if active_nodes == 0:  # Empty graph is connected
            connected = True
        results.append("Yes" if connected else "No")

    print("\n".join(results))

solve()
