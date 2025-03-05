from math import ceil


for _ in range(int(input())):
    n, w = map(int, input().split())
    items = list(map(int, input().split()))
    s = 0
    ans = []
    for i in range(1, len(items) + 1):
        if items[i-1] <= w:
            s += items[i-1]
            if s <= w:
                ans.append(i)
            else:
                s -= items[i-1]
    if s >= ceil(w/2):
        print(len(ans))
        print(' '.join(list(map(str, ans))))
    else:
        print(-1)
