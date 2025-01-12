a = [0]
for i in range(1, 3000):
    if i % 3 != 0 and i % 10 != 3:
        a.append(i)
for _ in range(int(input())):
    print(a[int(input())])