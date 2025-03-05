n = int(input())
pages = list(map(int, input().split()))
i = 0
while n > 0:
    if i == 7:
        i = 0
    n -= pages[i]
    i += 1
print(i)
