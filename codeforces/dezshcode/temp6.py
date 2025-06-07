n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

i = 0
j = 0
ans = 0
while True:
    if a[i] == b[j]:
        i += 1
        j += 1
    else:
        while a[i] != b[j] and i <= n:
            i += j
            if a[i] == b[j]:
                ans += 1
