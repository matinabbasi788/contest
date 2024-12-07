a = int(input())
b = int(input())
c = int(input())
a = [a+b+c, (a+b)*c, a*b*c, a*(b+c)]
print(max(a))