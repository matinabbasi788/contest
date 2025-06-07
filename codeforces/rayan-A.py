q, t = map(int, input().split())
ans = []
# ans.append('Kourosh')
# ans.append('Zarir')
# ans.append('Arash')
# ans.append('Morshed')

ans.append('Kourosh')
for _ in range(t):
    ans.append('Zarir')
    ans.append('Arash')
    ans.append('Morshed')

for _ in range(q):
    i = int(input())
    print(ans[(i % (t + 1)) - 1])
