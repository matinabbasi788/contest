ans = []
for _ in range(int(input())):
    l, r = map(int, input().split())
    df = r - l
    n = 0
    while n * (n - 1) / 2 <= df:
        n += 1
    n -= 1
    ans.append(str(n))
print('\n'.join(ans))
