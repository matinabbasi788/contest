k = int(input())
l, r = map(int, input().split())
a = []
for i in range(k):
    a.append(float(input()))
x = a[0]/2
y = a[1]/2
print(min(x, y))
print(max(x, y))
