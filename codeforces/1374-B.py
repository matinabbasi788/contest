for _ in range(int(input())):
    cnt2 = 0
    cnt3 = 0
    n = int(input())
    while n % 2 == 0:
        n /= 2
        cnt2 += 1
    while n % 3 == 0:
        n /= 3
        cnt3 += 1
    if n != 1:
        print(-1)
    elif cnt2 > cnt3:
        print(-1)
    else:
        print((cnt3 - cnt2) + cnt3)
