def solve():
    a = int(input())
    for i in range(0, 100):
        for j in range(0, 100):
            if ((i+j)**2) == a:
                print(i, j)
                return
    print(-1)


for _ in range(int(input())):
    solve()
