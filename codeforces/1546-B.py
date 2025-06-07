for _ in range(int(input())):
    n, m = map(int, input().split())
    words = [input().strip() for _ in range(n * 2 - 1)]
    s = []
    for j in range(m):
        xor_sum = 0
        for i in range(2 * n - 1):
            xor_sum ^= ord(words[i][j])
        print(xor_sum)
        s.append(chr(xor_sum))
    print("".join(s))
