n = int(input())
ans = ""
for i in range(n):
    if i % 2 == 0:
        ans += "I hate that "
    else:
        ans += "I love that "
print(ans[:-5] + "it")