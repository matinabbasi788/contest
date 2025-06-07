n = int(input())
l = []
for i in range(n // 2, 0, -1):
    if n % i == 0:
        l.append(i)
        
if sum(l) == n:
    print("YES")
else:
    print("NO")
