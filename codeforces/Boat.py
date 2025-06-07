n, w = map(int, input().split())
a = list(map(int, input().split()))

i = 0
j = n-1
a.sort()
couple = 0
single = 0
m = max(a)
while a:
    if a[i] + a[j] <= w and i != j:
        couple += 1
        if a:
            a.pop()
        j -= 1
        if len(a) == 1:
            break
    else:
        single += 1
        a.pop()
        j -= 1
ans = 0
# print(couple, single)
if (couple == 0 and single > 1) or m > w:
    print(-1)
elif single == 1 and couple == 0:
    print(1)
else:
    # if couple:
    #     ans += (couple - 1) * 2 + 1
    # if single:
    #     ans += (single - 1) * 2 + 1
    ans += 2 * (couple + (single * 2)) - 1
    print(ans)
