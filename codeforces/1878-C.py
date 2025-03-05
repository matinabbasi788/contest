def can_select_k_numbers(n, k, x):
    S_min = k * (k + 1) // 2
    S_max = k * (2 * n - k + 1) // 2
    return S_min <= x <= S_max


t = int(input())
for _ in range(t):
    n, k, x = map(int, input().split())
    if can_select_k_numbers(n, k, x):
        print("YES")
    else:
        print("NO")
