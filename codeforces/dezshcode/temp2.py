s = input()

ans = 0
# s = s[::-1]
for i in range(1, len(s)):
    if s[i-1] == '(' and s[i] == '(':
        for j in range(i, len(s)):
            if s[j-1] == ')' and s[j] == ')':
                ans += 1
print(ans)
