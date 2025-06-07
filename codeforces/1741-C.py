for _ in range(int(input())):
    best = []
    n = int(input())
    ans = []
    a = list(map(int, input().split()))
    b = 0
    temp = 0
    for i in range(n):
        b += 1
        temp += a[i]
        c = temp
        num_op = 0
        for j in range(i+1, n):
            c -= a[j]
            num_op += 1
            if c == 0:
                c = temp
                ans.append(num_op)
            if c < 0:
                break
    print(c)
    if c != temp:
        best = n
    else:
        best = min(ans)
    print(best)
    # if ans:
    #     print(min(ans))
    # else:
    #     print(n)
