for _ in range(int(input())):
    n, k = map(int, input().split())
    if k > n:
        print("NO")
        continue
    if n == k:
        print("YES")
        for i in range(k):
            print(1, end=' ')
        print()
        continue
    if (n - (k-1) * 2) % 2 == ((k-1) * 2) % 2 and (n-(k-1)*2) > 0:
        print("YES")
        for i in range(k-1):
            print(2, end=' ')
        print(n - (k-1) * 2)
    elif ((n - (k-1)) % 2) == 1:
        print("YES")
        for i in range(k-1):
            print(1, end=' ')
        print(n - (k-1))
    else:
        print("NO")
