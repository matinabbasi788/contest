def min2(r):
    if r == 0:
        return 2
    p = bin(r).count('1')
    if p >= 2:
        return r
    for k in range(0, 31):
        if ((r >> k) & 1) == 0:
            s = 1 << k
            return r + 2 * s
    return r + 2


T = int(input())
for _ in range(T):
    n, x = map(int, input().split())
    if (n & x) != x:
        print(-1)
        continue

    ans = float('inf')
    maxk = min(n.bit_length(), 30)
    for k in range(1, maxk + 1):
        xorOnes = ((1 << (n.bit_length() - k)) - 1)
        r = x ^ xorOnes
        sk = float('inf')
        if k == 1:
            if (r & x) == x:
                sk = r
        elif k == 2:
            sk = min2(r)
        else:
            if r == 0 and k == 3:
                sk = 6
            elif bin(r).count('1') == k:
                sk = r
        if sk != float('inf'):
            ans = min(ans, sk)

    print(ans if ans != float('inf') else -1)
