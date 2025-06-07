def build_suffix_array(s):
    n = len(s)
    if n == 0:
        return []
    suffixes = sorted((s[i:], i) for i in range(n))
    return [suffix[1] for suffix in suffixes]

def build_lcp_array(s, suffix_array):
    n = len(s)
    if n == 0:
        return [0]
    rank = [0] * n
    lcp = [0] * (n - 1)
    
    for i, suffix in enumerate(suffix_array):
        rank[suffix] = i
    
    h = 0
    for i in range(n):
        if rank[i] > 0:
            j = suffix_array[rank[i] - 1]
            while i + h < n and j + h < n and s[i + h] == s[j + h]:
                h += 1
            lcp[rank[i] - 1] = h
            if h > 0:
                h -= 1
    
    return [0] + lcp

def solve(s):
    if not s:
        print("1")
        print("0 0")
        return
    
    suffix_array = build_suffix_array(s)
    lcp_array = build_lcp_array(s, suffix_array)
    
    print(" ".join(map(str, [x + 1 for x in suffix_array])))
    print(" ".join(map(str, lcp_array)))

# نمونه تست
s = input().strip()
solve(s)

