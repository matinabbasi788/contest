def solve(a, l, r, k):
    ans = 0
    ans += a[l-1]
    ans += a[-1] - a[r]
    ans += (r-l+1) * k
    if ans % 2 == 1:
        return True
    else:
        return False


for _ in range(int(input())):
    n, q = map(int, input().split())
    a = list(map(int, input().split()))
    b = [0]
    b.append(a[0])
    for i in range(2, n+1):
        b.append(b[i-1] + a[i-1])
    for i in range(q):
        l, r, k = map(int, input().split())
        if solve(b, l, r, k):
            print("YES")
        else:
            print("NO")
