for _ in range(int(input())):
    n = int(input())
    if n % 4 != 0:
        print("NO")
    else:
        print("YES")
        n //= 2
        for i in range(1, n+1):
            print(i * 2, end=' ')
        for i in range(1, n):
            print(i * 2 - 1, end=' ')
        print(n * 3 - 1)
