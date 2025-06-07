def solve(a, n):
    io = ie = n
    jo = je = -1
    for i in range(n):
        if (a[i] % 2) == 0:
            ie = min(ie, i)
            je = max(je, i)
        else:
            io = min(io, i)
            jo = max(jo, i)
    even = odd = 0
    if ie <= je:
        even = je - ie + 1
    if io <= jo:
        odd = jo - io + 1
    return n - max(even, odd)


for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    print(solve(a, n))
