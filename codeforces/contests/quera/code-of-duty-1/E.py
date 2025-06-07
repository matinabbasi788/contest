n = input()
n = n.split(' ')
l = [1, 1, 2, 2, 2, 8]
for i in range(len(n)):
    print(-(int(n[i]) - l[i]), end=' ')
