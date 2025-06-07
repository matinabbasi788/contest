for _ in range(int(input())):
    n = int(input())
    ans = n
    v = []
    a = list(map(int, input().split()))
    a = list(set(a))
    for i in range(len(a)):
        if not a[i]:
            continue
        t = 0b1111111111111111111111111111111 - a[i]
        for j in range(i+1, len(a)):
            if a[j] == t:
                ans -= 1
                a[i] = None
                a[a.index(t)] = None
                break
    print(ans)
