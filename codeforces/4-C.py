a = {}
n = int(input())
for _ in range(n):
    temp = input()
    if temp not in a:
        print("OK")
        a[temp] = 1
    else:
        print(f"{temp}{a[temp]}")
        a[temp] += 1
