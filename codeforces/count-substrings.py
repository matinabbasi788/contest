def count_distinct_substrings(s):
    n = len(s)
    
    # Validate input
    if not (1 <= n <= 400000):
        return "Error: String length must be between 1 and 400000"
    if not s.islower() or not s.isalpha():
        return "Error: String must contain only lowercase English letters"
    
    # Step 1: Build suffix array (simplified version)
    suffixes = [(s[i:], i) for i in range(n)]
    suffixes.sort()  # Sort by suffix string
    
    # Step 2: Count distinct substrings using LCP
    total = n - suffixes[0][1]  # Length of first suffix
    
    # Compare adjacent suffixes
    for i in range(1, n):
        curr_suffix, curr_idx = suffixes[i]
        prev_suffix, prev_idx = suffixes[i-1]
        
        # Compute LCP (Longest Common Prefix) length
        lcp = 0
        for j in range(min(len(curr_suffix), len(prev_suffix))):
            if curr_suffix[j] != prev_suffix[j]:
                break
            lcp += 1
        
        # Add new unique characters from current suffix
        total += (n - curr_idx) - lcp
    
    return total

# Get input and print result
s = input().strip()
result = count_distinct_substrings(s)
print(result)
