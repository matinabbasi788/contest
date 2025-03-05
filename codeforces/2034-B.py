for _ in range(int(input())):
    n, m, k = map(int, input().split())
    s = input()
    ps = [0] * n
    ans = sum_ = cnt = 0
    for i in range(n):
        sum_ += ps[i]
        if sum_ or s[i] == '1':
            cnt = 0
        else:
            cnt += 1
            if cnt == m:
                cnt = 0
                ans += 1
                sum_ += 1
                if i + k < n:
                    ps[i + k] -= 1
    print(ans)
