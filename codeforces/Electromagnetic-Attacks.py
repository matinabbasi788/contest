import sys

def readints():
    return list(map(int, sys.stdin.readline().split()))

def cross(o, a, b):
    return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0])

def convex_hull(points):
    points = sorted(points)
    lower = []
    for p in points:
        while len(lower) >= 2 and cross(lower[-2], lower[-1], p) <= 0:
            lower.pop()
        lower.append(p)
    upper = []
    for p in reversed(points):
        while len(upper) >= 2 and cross(upper[-2], upper[-1], p) <= 0:
            upper.pop()
        upper.append(p)
    return lower[:-1] + upper[:-1]

def is_outside_rect(p, x1, y1, x2, y2):
    x, y = p
    return x < x1 or x > x2 or y < y1 or y > y2

def intersects_vertical(A, B, x_val, y_min, y_max):
    xa, ya = A
    xb, yb = B
    if xa == xb:
        if xa == x_val:
            if (ya < y_min and yb > y_min) or (yb < y_min and ya > y_min):
                return True
            if (ya < y_max and yb > y_max) or (yb < y_max and ya > y_max):
                return True
            if (ya <= y_max and yb >= y_min) or (yb <= y_max and ya >= y_min):
                return True
            return False
        else:
            return False
    t = (x_val - xa) / (xb - xa)
    if not (0 <= t <= 1):
        return False
    y = ya + t * (yb - ya)
    if y_min <= y <= y_max:
        return True
    return False

def intersects_horizontal(A, B, y_val, x_min, x_max):
    xa, ya = A
    xb, yb = B
    if ya == yb:
        if ya == y_val:
            if (xa < x_min and xb > x_min) or (xb < x_min and xa > x_min):
                return True
            if (xa < x_max and xb > x_max) or (xb < x_max and xa > x_max):
                return True
            if (xa <= x_max and xb >= x_min) or (xb <= x_max and xa >= x_min):
                return True
            return False
        else:
            return False
    t = (y_val - ya) / (yb - ya)
    if not (0 <= t <= 1):
        return False
    x = xa + t * (xb - xa)
    if x_min <= x <= x_max:
        return True
    return False

def segment_intersects_rect(A, B, x1, y1, x2, y2):
    min_x = min(A[0], B[0])
    max_x = max(A[0], B[0])
    min_y = min(A[1], B[1])
    max_y = max(A[1], B[1])
    if max_x < x1 or min_x > x2 or max_y < y1 or min_y > y2:
        return False
    if intersects_vertical(A, B, x1, y1, y2):
        return True
    if intersects_vertical(A, B, x2, y1, y2):
        return True
    if intersects_horizontal(A, B, y1, x1, x2):
        return True
    if intersects_horizontal(A, B, y2, x1, x2):
        return True
    return False

def main():
    n, m, k = map(int, sys.stdin.readline().split())
    points = []
    for _ in range(n):
        x, y = map(int, sys.stdin.readline().split())
        points.append((x, y))
    # Compute convex hull
    convex = convex_hull(points)
    # Read edges (not used, since we only need convex hull)
    for _ in range(m):
        a, b = readints()
    # Process each query
    for _ in range(k):
        x1, y1, x2, y2 = map(int, sys.stdin.readline().split())
        # Collect convex hull vertices outside the rectangle
        outside = []
        for p in convex:
            if is_outside_rect(p, x1, y1, x2, y2):
                outside.append(p)
        if len(outside) < 2:
            print("Yes")
            continue
        # Check consecutive edges in the convex hull order
        found = False
        for i in range(len(outside)):
            a = outside[i]
            b = outside[(i+1)%len(outside)]
            if not segment_intersects_rect(a, b, x1, y1, x2, y2):
                found = True
                break
        if found:
            print("Yes")
        else:
            print("No")

if __name__ == "__main__":
    main()
