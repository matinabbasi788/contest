a = [2 ** i for i in range(50)]

for _ in range(int(input())):
    n = int(input())
    if n in a:
        print("NO")
    else:
        print("YES")
