a = []
n = int(input())
for i in range(n):
    x, y = map(int, input().split())
    a.append((x, y))


def solve():
    a.sort()
    for i in range(n - 1):
        if a[i][1] > a[i+1][1]:
            return "Happy Alex"
    return "Poor Alex"


print(solve())
