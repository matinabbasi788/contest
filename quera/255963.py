# رژیم مالی https://quera.org/problemset/255963

t = int(input())
for _ in range(t):
    k, j = map(int, input().split())
    kabab, joje, mix = map(int, input().split())
    if mix == min(kabab, mix) or mix == min(joje, mix):
        print(mix + min((k-1)*kabab, (j-1)* joje))
    else:
        print(min((k//2 * kabab) + (j//2 * joje), max(k, j) * mix, mix + min(k*kabab, j* joje)))