def solve():
    x = input()
    y = input()
    if set(x) == set(y) and y.count('R') <= x.count('R') and y.count('L') <= x.count('L'):
        print("YES")
    else:
        print("NO")


for _ in range(int(input())):
    solve()
