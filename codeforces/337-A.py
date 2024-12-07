n, m = map(int, input().split())
l = sorted(list(map(int, input().split())))
ans = float('inf')
for k in range(0, m-n):
    ans = min(ans, l[k + n - 1] - l[k])
print(ans)
    
# for i in range(len(l)):
#     for j in range(i+1, len(l)):
#         for k in range(j+1, len(l)):
#             for h in range(k+1, len(l)):
#                 if max(l[i], l[j], l[k], l[h]) - min(l[i], l[j], l[k], l[h]) <= ans:
#                     ans = max(l[i], l[j], l[k], l[h]) - min(l[i], l[j], l[k], l[h])
# print(ans)