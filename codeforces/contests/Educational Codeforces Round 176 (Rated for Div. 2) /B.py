t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    sorted_a = sorted(a, reverse=True)
    prefix_sum = [0] * (n + 1)
    for i in range(n):
        prefix_sum[i+1] = prefix_sum[i] + sorted_a[i]
    M = sorted_a[0]
    cnt = 0
    for num in sorted_a:
        if num == M:
            cnt += 1
        else:
            break
    sum1 = prefix_sum[k]
    next_max = sorted_a[k] if k < n else 0
    cost1 = sum1 + next_max
    non_m_count = n - cnt
    cost2 = -float('inf')
    if non_m_count >= k:
        sum_non_m = prefix_sum[cnt + k] - prefix_sum[cnt]
        cost2 = sum_non_m + M
    ans = max(cost1, cost2)
    print(ans)
