n = int(input())
a = []
for i in range(n):
    a.append(input())
a.sort(key=len)
for i in range(len(a)):
    for j in range(i+1, len(a)):
        if a[i] not in a[j]:
            print("NO")
            exit()
else:
    print("YES")
    print('\n'.join(a))
