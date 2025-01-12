from math import ceil


for _ in range(int(input())):
    a, b = map(int, input().split())
    if a > b:
        ans = abs(a - b) // 10
        if abs(a-b) % 10 != 0:
            print(ans + 1)
        else:
            print(ans)
    else:
        ans = abs(b - a) // 10
        if abs(b-a) % 10 != 0:
            print(ans + 1)
        else:
            print(ans)
