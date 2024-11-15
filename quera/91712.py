x2, x1 = list(map(int, input().split()))

if x1 > x2:
    print(abs(x1-x2)*'R')
elif x1 < x2:
    print(abs(x2-x1)*'L')
else:
    print("Saal Noo Mobarak!")