for _ in range(int(input())):
    a, b = map(int, input().split())
    print(min(max(2 * b, a), max(2 * a, b)) ** 2)