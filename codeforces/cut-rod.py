def cut_rod(p, n):
    if n <= 0:
        return 0
    max_ = -1
    for i in range(n):
        max_ = max(max_, p[i] + cut_rod(p, n - i - 1))
    return max_


n = int(input())
l_p = list(map(int, input().split()))
print(cut_rod(l_p, n))
