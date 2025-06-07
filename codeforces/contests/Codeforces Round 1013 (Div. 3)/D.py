import sys

t = int(sys.stdin.readline())
for _ in range(t):
    n, m, k = map(int, sys.stdin.readline().split())
    if n > m:
        n, m = m, n  # swap to make n the smaller one, but actually it doesn't matter for the calculation
    max_per_row = (k + n - 1) // n  # ceil(k / n)
    if max_per_row <= m:
        print(max_per_row)
    else:
        # All rows have m desks, then distribute remaining k - n*m desks, but since k <=n*m, this case won't happen per problem constraints?
        # Wait, no. For example, if n=1, m=5, k=4: max_per_row is 4, which is <=5. So output 4.
        # So the initial condition covers all cases.
        print(m)
