s = list(input())
for i in range(1, len(s)):
    print(''.join(s))
    for j in range(i):
        s[j] = s[i]
print(s[-1] * len(s))