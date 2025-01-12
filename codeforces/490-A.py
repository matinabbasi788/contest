n = int(input())
array = list(map(int, input().split()))
l = min([array.count(1), array.count(2), array.count(3)])
print(l)
c = 1
a = 0
for i in range(l * 3):
    print(array.index(c) + 1, end=' ')
    array[array.index(c)] = 0
    c += 1
    if c == 4:
        print()
        c = 1
    
