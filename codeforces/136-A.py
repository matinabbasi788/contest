n = int(input())
array = list(map(int, input().split()))
ans = [0 for _ in range(n)]
for i in range(n):
    ans[array[i] - 1] = i + 1
print(' '.join(map(str, ans)))