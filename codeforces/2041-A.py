a = list(map(int, input().split()))
b = [1, 2, 3, 4, 5]
for i in a:
    b.remove(i)
print(b[0])