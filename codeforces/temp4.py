import sys

def main():
    input = sys.stdin.read().split()
    ptr = 0
    n = int(input[ptr]); ptr +=1
    m = int(input[ptr]); ptr +=1
    k = int(input[ptr]); ptr +=1

    nodes = []
    for _ in range(n):
        x = int(input[ptr]); ptr +=1
        y = int(input[ptr]); ptr +=1
        nodes.append((x, y))

    edges = []
    for _ in range(m):
        u = int(input[ptr])-1; ptr +=1
        v = int(input[ptr])-1; ptr +=1
        edges.append((u, v))

    for _ in range(k):
        x1 = int(input[ptr]); ptr +=1
        y1 = int(input[ptr]); ptr +=1
        x2 = int(input[ptr]); ptr +=1
        y2 = int(input[ptr]); ptr +=1

        # Check if all nodes are inside the attack region
        all_inside = True
        for (x, y) in nodes:
            if not (x1 <= x <= x2 and y1 <= y <= y2):
                all_inside = False
                break
        if all_inside:
            print("Yes")
            continue

        # Collect surviving nodes
        survivors = set()
        for i in range(n):
            x, y = nodes[i]
            if x < x1 or x > x2 or y < y1 or y > y2:
                survivors.add(i)

        if not survivors:
            print("Yes")
            continue

        # Check if any edge between survivors does not intersect the rectangle
        connected = False
        for u, v in edges:
            if u not in survivors or v not in survivors:
                continue
            ux, uy = nodes[u]
            vx, vy = nodes[v]

            # Check if the edge (u, v) intersects the rectangle
            # This is a simplified check and might not cover all cases
            # Proper line-rectangle intersection needed
            left = max(min(ux, vx), x1)
            right = min(max(ux, vx), x2)
            bottom = max(min(uy, vy), y1)
            top = min(max(uy, vy), y2)
            if left <= right and bottom <= top:
                # Possible intersection, need more precise check
                pass
            else:
                connected = True
                break

        if connected:
            print("Yes")
        else:
            print("No")

if __name__ == "__main__":
    main()
