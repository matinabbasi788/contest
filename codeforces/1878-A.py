for _ in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    print("YES" if k in a else "NO")
