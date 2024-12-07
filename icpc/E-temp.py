def max_sum(n, k, row1, row2):
    row1 = list(map(int, row1.split()))
    row2 = list(map(int, row2.split()))
    
    row1_sorted = sorted(row1, reverse=True)
    row2_sorted = sorted(row2, reverse=True)

    max_sum_row1 = sum(row1_sorted[:k])
    max_sum_row2 = sum(row2_sorted[:k])
    
    if k == 2:
        return (max_sum_row1 + max_sum_row2) // 2
    
    return max_sum_row1 + max_sum_row2

n, k = list(map(int, input().split()))
row1 = input()
row2 = input()

result = max_sum(n, k, row1, row2)
print(result)
