for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = sum(a)
    if b ** 0.5 == int(b ** 0.5):
        print("YES")
    else:
        print("NO")
