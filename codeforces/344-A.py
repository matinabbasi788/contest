n = int(input())
ans = 0
temp = 0
for i in range(n):
    magnet = input()
    if temp != magnet:
        ans += 1
        temp = magnet
print(ans)