a = int(input())
ans = 0
n = a
for i in range(1, n+1):
    ans += sum(range(0, i+1))
    if ans + sum(range(0, i+2)) > a:
        print(i)
        break
    elif ans == a:
        print(i)
        break

