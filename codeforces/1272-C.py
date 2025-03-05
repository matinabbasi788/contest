n, k = map(int, input().split())
s = input()
c = list(input().split())
a = [0 for _ in range(n + 1)]
typeable = [0 for _ in range(26)]  # a -> z [0, 25]
ans = 0
for i in c:
    typeable[ord(i) - ord('a')] = 1  # typetable[i - 'a'] = 1

for i in range(n):
    if typeable[ord(s[i]) - ord('a')]:
        a[i] = 1
    else:
        a[i] = 0

f = [0 for _ in range(n + 1)]
f[0] = 0
for i in range(n):
    if a[i] == 0:
        f[i + 1] = 0
    else:
        f[i + 1] = f[i] + 1
    ans += f[i + 1]


print(ans)
