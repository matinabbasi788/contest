import sys
import math

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
        if n == 2:
            print(abs(a[0] - a[1]))
            continue
        overall_gcd = 0
        for i in range(n):
            for j in range(i + 1, n):
                diff = abs(a[i] - a[j])
                overall_gcd = math.gcd(overall_gcd, diff)
        print(overall_gcd if overall_gcd != 0 else 1)

solve()
