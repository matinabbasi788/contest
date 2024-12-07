n, m = map(int, input().split())
flg = True
for i in range(n):
    if i % 2 == 0:
        print('#' * m)
    elif i % 2 == 1 and flg:
        print('.' * (m - 1), end='')
        print('#')
        flg = False
    elif i % 2 == 1 and not flg:
        print('#', end='')
        print('.' * (m - 1))
        flg = True
        