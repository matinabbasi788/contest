n = int(input())
a = []
for i in range(n):
    a.append(input())
b = list(set(a))
if len(b) == 1:
    print(b[0])
elif a.count(b[0]) > a.count(b[1]):
    print(b[0])
else:
    print(b[1])
