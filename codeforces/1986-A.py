for i in range(int(input())):
    a = list(map(int, input().split()))
    print(abs(max(a) - min(a)))
