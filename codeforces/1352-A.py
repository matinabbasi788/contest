t = int(input())
for _ in range(t):
    a = {}
    c = 0
    s = input()
    b = [1 * i for i in range(1, len(s))]
    for i in s:
        if i != '0':
            c = i
            b[]
        else:
            a[int(c)] += 1
    c = 0
    temp = list(a.values())
    print(len(a))
    for i in a:
        print(i, '0' * len(s[c+1:]), sep='', end=' ')
        c += 1
    print()