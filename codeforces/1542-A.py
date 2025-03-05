for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    odd = 0
    even = 0
    for i in a:
        if i % 2 == 0:
            even += 1
        else:
            odd += 1
    if odd == n and even == n:
        print("YES")
    else:
        print("NO")
