s = input()
a = 0
b = 0
ans = 0
for i in s:
    if i == '(':
        a += 1
    else:
        b += 1
print(min(a, b) + (max(a, b) - min(a, b)) // 2)
