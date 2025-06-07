for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    even = 0
    odd = 0
    for i in a:
        if i & 1 == 0:
            even += 1
        else:
            odd += 1
    if (even >= 1 and odd >= 1) or (odd >= 1 and n & 1 == 1):
        print("YES")
    else:
        print("NO")
