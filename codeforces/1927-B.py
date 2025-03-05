def solve():
    n = int(input())
    a = list(map(int, input().split()))
    cnt = [0] * 26  # Tracks the count of each character (a-z)
    s = []
    for i in range(n):
        # Find the smallest character with count == a[i]
        for j in range(26):
            if cnt[j] == a[i]:
                s.append(chr(97 + j))  # Append the character
                cnt[j] += 1  # Increment its count
                break
    print(''.join(s))


for _ in range(int(input())):
    solve()
