def find_min_difference(n, values):
    prefix_sum = [0] * (n + 1)
    for i in range(1, n + 1):
        prefix_sum[i] = prefix_sum[i - 1] + values[i - 1]
    
    min_diff = float('inf')

    for j in range(2, n - 1): 
        left = 1
        right = j - 1
        while left < right:
            mid = (left + right) // 2
            if abs(prefix_sum[mid] - (prefix_sum[j] - prefix_sum[mid])) > abs(prefix_sum[mid + 1] - (prefix_sum[j] - prefix_sum[mid + 1])):
                left = mid + 1
            else:
                right = mid
        i = left

        left = j + 1
        right = n
        while left < right:
            mid = (left + right) // 2
            if abs(prefix_sum[mid] - prefix_sum[j] - (prefix_sum[n] - prefix_sum[mid])) > abs(prefix_sum[mid + 1] - prefix_sum[j] - (prefix_sum[n] - prefix_sum[mid + 1])):
                left = mid + 1
            else:
                right = mid
        k = left

        p1 = prefix_sum[i]
        p2 = prefix_sum[j] - prefix_sum[i]
        p3 = prefix_sum[k] - prefix_sum[j]
        p4 = prefix_sum[n] - prefix_sum[k]

        max_val = max(p1, p2, p3, p4)
        min_val = min(p1, p2, p3, p4)
        min_diff = min(min_diff, max_val - min_val)
    
    return min_diff

n = int(input())
values = list(map(int, input().split()))

result = find_min_difference(n, values)
print(result)