a = input()
b = input().split()
for i in b:
    if i[0] == a[0] or i[1] == a[1]:
        print("YES")
        break
else:
    print("NO")
