text = input()
u = 0
l = 0
for i in text:
    if i == i.upper():
        u += 1
    else:
        l += 1
if u > l:
    print(text.upper())
else:
    print(text.lower())