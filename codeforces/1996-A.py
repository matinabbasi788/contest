for _ in range(int(input())):
    n = int(input())
    ans = 0
    ans += n // 4
    ans += (n % 4) / 2
    print(int(ans))
