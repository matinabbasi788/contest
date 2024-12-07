n = int(input())
lnums = [4, 7, 47, 74, 477, 474, 444, 744, 747, 777, 774]
for i in lnums:
    if n % i == 0:
        print("YES")
        break
else:
    print("NO")