n = int(input())
a = list(map(int, input().split()))
for i in range(n):
    if i == 0:
        mn = abs(a[i] - a[i+1])
        mx = abs(a[i] - a[-1])
    elif i == n-1:
        mn = abs(a[i] - a[i-1])
        mx = abs(a[i] - a[0])
    else:
        mn = min(abs(a[i] - a[i-1]), abs(a[i] - a[i+1]))
        mx = max(abs(a[i] - a[-1]), abs(a[i] - a[0]))
    print(f"{mn} {mx}")
