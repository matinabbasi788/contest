

def solve():
    n = int(input())
    a = [i[-1] for i in input().split()]
    a = list(map(int, a))
    a.sort()
    for i in range(n):
        for j in range(i+1, n):
            for k in range(j+1, n):
                if str(a[i] + a[j] + a[k])[-1] == '3':
                    print("YES")
                    return
    print("NO")


for _ in range(int(input())):
    solve()
