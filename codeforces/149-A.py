k = int(input())
a = list(map(int, input().split()))
a.sort(reverse=True)
for i in range(12):
    if k <= 0:
        print(i)
        break
    k -= a[i]
    if k <= 0:
        print(i+1)
        break
else:
    print(-1)
