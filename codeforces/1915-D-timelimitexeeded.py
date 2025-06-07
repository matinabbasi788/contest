import sys
input = sys.stdin.readline


v = ['a', 'e']
c = ['b', 'c', 'd']


for _ in range(int(input())):
    ans = ''
    n = int(input())
    s = input()
    i = n-1
    while i > 0:
        if s[i] in v and s[i-1] in c:
            ans += f"{s[i]}{s[i-1]}."
            i -= 2
        elif s[i] in c and s[i-1] in v and s[i-2] in c:
            ans += f"{s[i]}{s[i-1]}{s[i-2]}."
            i -= 3
    print(ans[::-1][1:])
