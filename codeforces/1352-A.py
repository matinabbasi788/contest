t = int(input())
for _ in range(t):
    a = input()
    print(len(a) - a.count('0'))
    for i in range(len(a)):
        if '0' not in a[i]:
            print(f"{a[i]}{'0' * (len(a) - i - 1)}", end=' ')
    print()
