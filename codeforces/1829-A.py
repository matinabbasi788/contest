a = "codeforces"
for _ in range(int(input())):
    b = input()
    ans = 0
    for i in range(len(b)):
        if a[i] != b[i]:
            ans += 1
    print(ans)