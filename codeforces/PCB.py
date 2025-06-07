import sys

def main():
    input = sys.stdin.read().split()
    ptr = 0
    W = int(input[ptr]); ptr += 1
    H = int(input[ptr]); ptr += 1
    n = int(input[ptr]); ptr += 1

    h = []
    for i in range(n):
        hi = int(input[ptr]); ptr += 1
        h.append((hi, i + 1))  # Store with 1-based index

    # Sort power supplies by their y-coordinate (h)
    h_sorted = sorted(h, key=lambda x: x[0])

    consumers = []
    for j in range(n):
        x = int(input[ptr]); ptr += 1
        y = int(input[ptr]); ptr += 1
        consumers.append((y, x, j + 1))  # Store y, x, 1-based index

    # Sort consumers by y, then by x to handle ties deterministically
    consumers_sorted = sorted(consumers, key=lambda c: (c[0], c[1]))

    # Create assignment from sorted power to sorted consumers
    assignment = {}
    for i in range(n):
        power_orig_idx = h_sorted[i][1]
        consumer_orig_idx = consumers_sorted[i][2]
        assignment[power_orig_idx] = consumer_orig_idx

    # Generate output in the order of original power supply indices
    output = []
    for orig_power in range(1, n + 1):
        output.append(str(assignment[orig_power]))

    print(' '.join(output))

if __name__ == '__main__':
    main()
