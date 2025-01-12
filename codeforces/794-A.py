n = int(input())
ans = num2 = num3 = 0

while n > 0:
    if n == 5:
        num2 += 1
        num3 += 1
        ans += 2
        n -= 5
    elif n == 3:
        num3 += 1
        ans += 1
        n -= 3
    else:
        num2 += 1
        ans += 1
        n -= 2
print(ans)
print(' '.join(['2' for i in range(num2)] + ['3' for j in range(num3)]))
