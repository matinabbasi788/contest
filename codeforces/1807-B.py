for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    odd = 0
    even = 0
    for i in arr:
        if i % 2 == 0:
            even += i
        else:
            odd += i
    print("YES" if even > odd else "NO")
