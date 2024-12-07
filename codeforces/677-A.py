from math import ceil
ans = 0
n, h = map(int, input().split())
for i in list(map(int, input().split())):
    ans += ceil(i / h)
    
print(ans)