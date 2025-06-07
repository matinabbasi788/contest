from collections import Counter


def solve_case(n, a, b):
    # Quick check: if arrays are identical, return any large k
    if sorted(a) == sorted(b):
        return min(31415926, 10**9)

    # Get frequency of b values
    b_freq = Counter(b)
    max_b = max(b)
    a_max = max(a)

    # All values in b must be < k, so minimum k is max(b) + 1
    min_k = max_b + 1

    # Key optimization: possible k values are related to differences
    # between a[i] and b[j] values
    possible_k = set()

    # For each a[i], b[j] pair, k could be a divisor of |a[i] - b[j]| + some offset
    for ai in a:
        for bj in b:
            diff = ai - bj
            if diff > 0:
                # k could be diff + x where x <= max_b
                for x in range(max_b + 1):
                    k = diff + x
                    if k >= min_k and k <= 10**9:
                        possible_k.add(k)
            elif diff < 0:
                # k could be related to how much we need to add to bj to reach ai
                k = ai + (max_b - bj) + 1
                if k >= min_k and k <= 10**9:
                    possible_k.add(k)

    # Sort possible k values for early exit
    possible_k = sorted(possible_k)

    # Check each possible k
    for k in possible_k:
        # Get remainders
        remainders = [x % k for x in a]
        if max(remainders) > max_b:
            continue

        # Compare frequencies
        if Counter(remainders) == b_freq:
            return k

        if k > a_max + max_b:
            break

    return -1


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        b = list(map(int, input().split()))
        result = solve_case(n, a, b)
        print(result)


if __name__ == "__main__":
    main()
