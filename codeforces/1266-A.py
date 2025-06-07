for _ in range(int(input())):
    y = input()
    if y.count('0') == len(y):
        print("red")
        continue
    a = list(map(int, y))
    b = y.count('2') + y.count('4') + y.count('6') + y.count('8')
    if sum(a) % 3 == 0 and len(y) > 1 and (b > 0 or y.count('0') > 1) and y.count('0') > 0:
        print("red")
    else:
        print("cyan")
