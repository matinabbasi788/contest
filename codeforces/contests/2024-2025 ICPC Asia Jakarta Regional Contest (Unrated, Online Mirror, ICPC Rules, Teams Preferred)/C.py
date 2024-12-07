def merge_strings(s1, s2):
    if s1 == s2:
        return s1  # If both strings are exactly the same, return either of them
    
    if len(s1) != len(s2):
        return -1  # If lengths are different, return -1
    
    result = []
    for c1, c2 in zip(s1, s2):
        if c1 == c2:
            result.append(c1)
        elif c1 == 'h' or c2 == 'h':  # If one of the characters is 'h'
            result.append('h')
        else:
            return -1  # If there is no way to resolve the conflict, return -1
    
    return ''.join(result)

# Example usage
s1 = "berhiber"
s2 = "wortelhijau"

output = merge_strings(s1, s2)
print(output)