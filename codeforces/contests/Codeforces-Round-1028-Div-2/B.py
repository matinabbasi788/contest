mod = 998244353


for _ in range(int(input())):
    ans = []
    n = int(input())
    p = list(map(int, input().split()))
    q = list(map(int, input().split()))
    pow_p = [2**i for i in p]
    pow_q = [2**i for i in q]
    temp = []
    j = 0
    for i in range(n):

        ans.append(max(temp))
    print(*ans)
