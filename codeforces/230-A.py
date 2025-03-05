# s, n = map(int, input().split())
# x = []
# y = []
# for i in range(n):
#     a, b = map(int, input().split())
#     x.append(a)
#     y.append(b)
# for i in range(n):
#     temp = min(x)
#     if s > temp:
#         s += y[x.index(temp)]
#         y.pop(x.index(temp))
#         x.pop(x.index(temp))
#     else:
#         print("NO")
#         break
# else:
#     print("YES")


"""
better implemantion
"""

s, n = map(int, input().split())
dragons = []
for _ in range(n):
    a, b = map(int, input().split())
    dragons.append((a, b))
dragons.sort()

for a, b in dragons:
    if s <= a:
        print("NO")
        break
    else:
        s += b
else:
    print("YES")
