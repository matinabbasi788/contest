k = int(input())
s = input()
ans = 0
for i in range(k):
    t = input()
    ans += min(t.index(s[i]), t[::-1].index(s[i])+1)
print(ans)

