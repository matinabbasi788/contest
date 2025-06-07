for _ in range(int(input())):
    s = input()
    a, b = s[0], int(s[1])
    for i in range(1, 9):
        if i != b:
            print(f"{a}{i}")
    c = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h']
    for i in c:
        if i != a:
            print(f"{i}{b}")
