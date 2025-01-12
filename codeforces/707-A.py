n, m = map(int, input().split())
for i in range(n):
    a = input().split()
    if 'C' in a or 'M' in a or 'Y' in a:
        print('#Color')
        break
else:
    print('#Black&White')