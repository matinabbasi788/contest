palindromes = []

for i in range(1, 1000):
    for j in range(1, 1000):
        s = str(i * j)
        if s == s[::-1]:
            palindromes.append(int(s))
print(sorted(palindromes, reverse=True)[0])
