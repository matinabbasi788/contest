n = int(input())
a = list(map(int, input().split()))
even = 1
odd = 1
te = 0
to = 0
for i in range(len(a)):
    if a[i] % 2 == 0:
        even = i + 1
        te += 1
    else:
        odd = i + 1
        to += 1
        
if te > to:
    print(odd)
else:
    print(even)