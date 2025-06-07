import sys
import math

def get_divisors(num):
    divisors = set()
    if num == 0:
        return divisors
    for i in range(1, int(math.isqrt(num)) + 1):
        if num % i == 0:
            divisors.add(i)
            divisors.add(num // i)
    return divisors

def solve():
    input = sys.stdin.read().split()
    ptr = 0
    t = int(input[ptr])
    ptr += 1
    for _ in range(t):
        n = int(input[ptr])
        ptr += 1
        a = list(map(int, input[ptr:ptr + n]))
        ptr += n
        unique_diffs = set()
        for i in range(n):
            for j in range(i + 1, n):
                diff = abs(a[i] - a[j])
                if diff != 0:
                    unique_diffs.add(diff)
        if not unique_diffs:
            print(1)
            continue
        candidates = set()
        for diff in unique_diffs:
            divisors = get_divisors(diff)
            candidates.update(divisors)
        candidates.discard(1)  # Remove 1 to find larger GCDs
        if not candidates:
            print(1)
            continue
        candidates = sorted(candidates, reverse=True)
        max_g = 1
        for g in candidates:
            mod_counts = {}
            for num in a:
                mod = num % g
                mod_counts[mod] = mod_counts.get(mod, 0) + 1
                if mod_counts[mod] >= 2:
                    max_g = g
                    break
            if max_g == g:
                break
        print(max_g)

solve()
