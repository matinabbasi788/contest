# روبرو در مترو https://quera.org/problemset/218361

l1 = list(map(int, input().split()))
l2 = list(map(int, input().split()))
cnt = 0
for i in range(len(l1)):
    if l1[i] == 1 and l2[i] == 1:
       cnt += 1
print(cnt) 