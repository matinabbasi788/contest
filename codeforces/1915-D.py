# import sys
# input = sys.stdin.readline  # Faster input reading


def solve():
    n = int(input().strip())
    s = input().strip()
    res = []

    i = len(s)  # Work backwards from end
    while i > 0:
        if s[i-1] in 'ae':  # Last char is 'a' or 'e'
            x = 2
        else:
            x = 3
        res.append(s[i-x:i][::-1])  # Add substring of length x
        i -= x
        res.append('.')  # Add separator

    # Join everything except the last '.' and reverse
    print(''.join(res[:-1])[::-1])


# Handle multiple test cases
tt = int(input().strip())
for _ in range(tt):
    solve()
