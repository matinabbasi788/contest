s = 0
s2 = 0
for i in range(101):
    s += i ** 2
    s2 += i
print(s2 ** 2 - s)
