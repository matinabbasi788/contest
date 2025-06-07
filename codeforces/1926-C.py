def a(n):
    ans = 0
    for i in range(1, n+1):
        ans += sum(map(int, str(i)))
    return ans


for i in range(1, 200000):
    print(f"{i}: {a(i)}")
