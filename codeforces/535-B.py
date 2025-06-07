a = []


def solve(num):
    a.append(num)
    if num > 1000000000:
        return
    solve(num * 10 + 4)
    solve(num * 10 + 7)


solve(0)
a.sort()
print(a.index(int(input())))
