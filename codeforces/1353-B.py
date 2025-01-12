for _ in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    for i in range(k):
        if max(b) > min(a):
            a[a.index(min(a))], b[b.index(max(b))] = b[b.index(max(b))], a[a.index(min(a))]
    print(sum(a))
