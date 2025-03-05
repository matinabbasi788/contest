for _ in range(int(input())):
    n = int(input())
    res = 0
    pw = 1
    while (pw <= n):
        for i in range(1, 10):
            if pw * i <= n:
                res += 1
        pw = pw * 10 + 1
    print(res)
