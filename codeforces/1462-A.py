for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    i = 0
    j = n-1
    while i < j:
        print(a[i], a[j], end=' ')
        i += 1
        j -= 1
    if n % 2 == 1:
        print(a[n//2], end='')
    print()
