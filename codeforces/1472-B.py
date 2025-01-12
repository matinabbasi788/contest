for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    cnt1 = arr.count(1)
    cnt2 = arr.count(2)
    if (cnt1 + cnt2 * 2) % 2 != 0:
        print("NO")
    else:
        sum = (cnt1 + 2 * cnt2) / 2
        if sum % 2 == 0 or (sum % 2 == 1 and cnt1 != 0):
            print("YES")
        else:
            print("NO")
