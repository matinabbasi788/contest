from collections import deque


def min_oprations(n, m):
    visited = set()
    q = deque()
    q.append((n, 0))

    while q:
        current, steps = q.popleft()

        if current == m:
            return steps

        new_value = current - 1
        if new_value > 0 and new_value not in visited:
            visited.add(new_value)
            q.append((new_value, steps + 1))

        new_value = current * 2
        if new_value <= 2 * m and new_value not in visited:
            visited.add(new_value)
            q.append((new_value, steps + 1))

    return -1


n, m = map(int, input().split())
print(min_oprations(n, m))
