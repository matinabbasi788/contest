for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    for i in range(n):
        if a.count(a[i]) == 1:
            print(i+1)
            break

