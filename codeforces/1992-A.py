for _ in range(int(input())):
    a = list(map(int, input().split()))
    for _ in range(5):
        for i in range(len(a)):
            if a[i] == min(a):
                a[i] += 1
                break
    print(a[0] * a[1] * a[2])
