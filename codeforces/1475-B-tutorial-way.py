for _ in range(int(input())):
    n = int(input())
    cnt2021 = n % 2020
    cnt2020 = (n - cnt2021) / 2020 - cnt2021
    if (cnt2020 >= 0 and 2020 * cnt2020 + 2021 * cnt2021 == n):
        print("YES")
    else:
        print("NO")
