n, t = map(int, input().split())
ans = 1 * 10 ** (n - 1)
if len(str(t)) > len(str(ans)):
    print(-1)
    exit()
elif ans % t == 0:
    pass
else:
    ans += t - (ans % t)
print(ans)
