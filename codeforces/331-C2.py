# String representing digits from 0 to 9
c = '0123456789'

# Dictionary to store precomputed results for specific digit combinations
F = {
    c[a] + c[b]: (c[10 - a + b], 1) if a > b else (c[10 - a], 2)
    for a in range(1, 10) for b in range(10)
}

# Additional base cases for the dictionary
for b in range(1, 10):
    F['0' + c[b]] = ('0', 1)
F['00'] = ('0', 0)


def f(x):
    global F
    # If the result for x is already computed, return it
    if x in F:
        return F[x]

    # Extract the first two digits and the rest of the number
    a, b, y, s = int(x[0]), int(x[1]), x[2:], 0

    # Try subtracting each digit from b down to a
    for i in range(b, a, -1):
        y, d = f(c[i] + y)
        s += d

    # Try subtracting each digit from 0 up to the minimum of a and b
    for i in range(min(a, b) + 1):
        y, d = f(x[0] + y)
        s += d

    # Store the computed result in the dictionary
    F[x] = ('9' + y, s)
    return F[x]


# Read input, prefix with '0', and print the minimum number of operations
print(f('0' + input())[1])
