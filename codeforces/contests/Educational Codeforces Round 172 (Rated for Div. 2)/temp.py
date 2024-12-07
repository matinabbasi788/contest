t = int(input())  # Number of test cases
index = 1
results = []

for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    index += n
    
    # Sort the chests in descending order
    a.sort(reverse=True)
    
    # Add coins to minimize the number Monocarp takes
    additional_coins = 0
    current_sum = 0
    
    for coins in a:
        current_sum += coins
        if current_sum >= k:
            break
    
    # If current_sum is less than k, calculate the coins needed to add
    if current_sum < k:
        additional_coins = k - current_sum
    
    results.append(additional_coins)

# Print all results
print("\n".join(map(str, results)))