for _ in range(int(input())):
    n = int(input())
    a = set()
    b = set()
    s = list(input())
    j = 0
    for i in range(len(s)):
        if s[i] in a:
            break
        a.add(s[i])
        j += 1
    for i in range(j, len(s)):
        b.add(s[i])
    # print(a)
    # print(b)
    print(len(a) + len(b))
