def solve(n, a):
    ans = a[0]
    for i in a[1:]:
        ans = ans & i
    return ans


for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    print(solve(n, a))
