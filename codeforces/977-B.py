from collections import Counter


n = int(input())
s = input()
ans = []
for i in range(1, n):
    ans.append(s[i-1:i+1])
cnt = Counter(ans)
print(max(cnt, key=cnt.get))
