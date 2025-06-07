mod = 998244353
s = [1]
for i in range(1, 100005):
    s.append((s[-1] * 2) % mod)


def solve():
    n = int(input())
    p = list(map(int, input().split()))
    q = list(map(int, input().split()))
    i = 0
    j = 0
    for k in range(n):
        if p[k] > p[i]:
            i = k
        if q[k] > q[j]:
            j = k
        if p[i] != q[j]:
            if p[i] > q[j]:
                print((s[p[i]] + s[q[k-i]]) % mod, end=' ')
            else:
                print((s[q[j]] + s[p[k-j]]) % mod, end=' ')
        else:
            print((s[p[i]] + s[max(q[k-i], p[k-j])]) % mod, end=' ')
    print()


for _ in range(int(input())):
    solve()
