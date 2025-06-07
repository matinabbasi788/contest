ax = [1, 2]
for i in range(15):
    ax.append(ax[-1] + ax[-2])


for _ in range(int(input())):
    ans = ''
    n, m = map(int, input().split())
    a, b = ax[n-1], ax[n-2]
    for i in range(m):
        t = list(map(int, input().split()))
        t.sort(reverse=True)
        if t[0] >= a+b and t[1] >= a and t[2] >= a:
            ans += '1'
        else:
            ans += '0'
    print(ans)
