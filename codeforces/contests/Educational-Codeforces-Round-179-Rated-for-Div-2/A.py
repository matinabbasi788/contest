for _ in range(int(input())):
    x = int(input())
    z = 64 - x.bit_length()
    z = 63 - z
    print(2 * z + 3)



