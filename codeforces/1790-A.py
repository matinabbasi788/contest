a = "314159265358979323846264338327"
for _ in range(int(input())):
    b = input()
    ans = 0
    for i in b:
        if i != a[ans]:
            break
        ans += 1
    print(ans)
