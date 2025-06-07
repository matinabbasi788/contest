import sys
import math


def sieve(limit):
    is_prime = [True] * (limit + 1)
    is_prime[0] = is_prime[1] = False
    for i in range(2, int(math.sqrt(limit)) + 1):
        if is_prime[i]:
            for j in range(i * i, limit + 1, i):
                is_prime[j] = False
    return is_prime


def count_interesting_ratios(n, is_prime):
    count = 0
    for a in range(1, n):
        for b in range(a + 1, n + 1):
            gcd_ab = math.gcd(a, b)
            F_ab = (a * b) // (gcd_ab * gcd_ab)
            if is_prime[F_ab]:
                count += 1
    return count


def main():
    input = sys.stdin.read
    data = input().split()
    t = int(data[0])
    cases = list(map(int, data[1:]))
    max_n = max(cases)

    is_prime = sieve(10**7)

    results = []
    for n in cases:
        results.append(str(count_interesting_ratios(n, is_prime)))

    sys.stdout.write("\n".join(results) + "\n")


if __name__ == "__main__":
    main()
