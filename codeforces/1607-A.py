for _ in range(int(input())):
    ans = 0
    alphabet = input()
    s = input()
    for i in range(len(s) - 1):
        ans += abs(alphabet.index(s[i]) - alphabet.index(s[i+1]))
    print(ans)
