def solve(s, a, b, ab, ba):
    while True:
        if max(a, b, ab, ba) == ba:
            for i in range(len(s)-1):
                if s[i] + s[i+1] == "BA":
                    ba -= 1
                    s[i] = '0'
                    s[i+1] = '0'
        if max(a, b, ab) == ab:
            for i in range(len(s)-1):
                if s[i] + s[i+1] == "AB":
                    ab -= 1
                    s[i] = '0'
                    s[i+1] = '0'
        if max(a, b) == b:
            for i in range(len(s)):
                if s[i] == "B":
                    a -= 1
                    s[i] = '0'
        for i in range(len(s)):
            if s[i] == "A":
                a -= 1
                s[i] = '0'
        print(a, b, ab, ba)
        if a < 0 or b < 0 or ba < 0 or ab < 0:
            return False
        else:
            return True


for _ in range(int(input())):
    s = input()
    a, b, ab, ba = map(int, input().split())
    print(solve(s, a, b, ab, ba))
