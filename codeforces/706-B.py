import bisect


n = int(input())
x = list(map(int, input().split()))
x.sort()
c = 0
q = int(input())
for _ in range(q):
    m = int(input())
    ans = bisect.bisect_right(x, m)
    print(ans)
