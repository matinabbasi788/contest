n, k = map(int, input().split())
a = list(map(int, input().split()))
if len(set(a)) < k:
    print("NO")
else:
    print("YES")
    b = list(set(a))
    for i in range(min(len(b), k)):
        print(a.index(b[i]) + 1, end=' ')
