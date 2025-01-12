for _ in range(int(input())):
    ans = 0
    l = list(map(int, input().split()))
    for i in l:
        ans ^= i
    print(ans)
