def solve():
    a = []
    input()
    for i in range(8):
        a.append(input())
    for i in a:
        if i == "RRRRRRRR":
            return "R"
    return "B"


for _ in range(int(input())):
    print(solve())
