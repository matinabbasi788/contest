ans = []
a = [1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111, 1111111111,
     11111111111, 111111111111, 1111111111111]
for i in a:
    for j in a:
        for k in a:
            if i + j + k not in ans:
                ans.append(i + j + k)
ans.sort()
n = int(input())
print(ans[n-1])
