a = [1]
for k in range(1, 40):
    a.append(2**(k) + a[k-1])
for _ in range(int(input())):
    n = int(input())
    for i in a[1:]:
        if n % i == 0:
            print(n//i)
            break
