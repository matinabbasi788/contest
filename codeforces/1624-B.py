def can_make_ap(a, b, c):
    # Check if already an AP
    if 2 * b == a + c:
        return True

    # Case 1: Modify a
    if (2 * b - c) % a == 0:
        m = (2 * b - c) // a
        if m > 0:
            return True

    # Case 2: Modify b
    if (a + c) % (2 * b) == 0:
        m = (a + c) // (2 * b)
        if m > 0:
            return True

    # Case 3: Modify c
    if (2 * b - a) % c == 0:
        m = (2 * b - a) // c
        if m > 0:
            return True

    # If none of the cases work
    return False


# Read input
t = int(input())
for _ in range(t):
    a, b, c = map(int, input().split())
    if can_make_ap(a, b, c):
        print("YES")
    else:
        print("NO")
