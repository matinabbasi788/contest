a = """
abcdefghijklmnopqrstuvwxyz
"""
ans = 0
c = 'a'
for i in input():
    d = abs(a.index(i) - a.index(c))
    if d > 13:
        d = 26 - d
    ans += d
    c = i
print(ans)
