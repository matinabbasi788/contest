def solve(s):
    a = int(s[0])
    op = s[1]
    b = int(s[2])

    if (op == '<' and a < b) or (op == '>' and a > b) or (op == '=' and a == b):
        return s

    if a < b:
        return f"{a}<{b}"
    elif a == b:
        return f"{a}={b}"
    else:
        return f"{a}>{b}"


for _ in range(int(input())):
    s = input()
    print(solve(s))
