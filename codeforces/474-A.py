d = input()
t = input()
k = r"qwertyuiopasdfghjkl;zxcvbnm,./"
if d == 'R':
    for i in t:
        print(k[k.index(i) - 1], end='')
    print()
else:
    for i in t:
        print(k[k.index(i) + 1], end='')
    print()