n = int(input())
a = list(map(int, input().split()))
m = int(input())
q = list(map(int, input().split()))
ans = []
cnt = 1
for i in a:
    t = 1
    while t <= i:
        ans.append(cnt)
        t += 1
    cnt += 1
for i in q:
    print(ans[i-1]) 