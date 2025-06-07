for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    uniq = []
    for x in a:
        if not uniq or uniq[-1] != x:
            uniq.append(x)
    ans = 0
    last = float('-inf')
    for v in uniq:
        if (v > last + 1):
            ans += 1
            last = v
    print(ans)
