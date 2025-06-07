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
        s = input[ptr]
        ptr += 1
        
        res = []
        B = 0
        prev_char = None
        for i in range(1, n + 1):
            current_char = s[i-1]
            if prev_char is not None and current_char != prev_char:
                B += 1
            prev_char = current_char
            
            if B == 0:
                res.append(i)
            else:
                # Compute number of divisors of B + 1 <= i
                m = B + 1
                divisors = set()
                for d in range(1, int(math.isqrt(m)) + 1):
                    if m % d == 0:
                        if d <= i:
                            divisors.add(d)
                        if (m // d) <= i:
                            divisors.add(m // d)
                cnt_div = len(divisors)
                # Compute max(0, i - (B + 1) + 1)
                extra = max(0, i - (B + 1) + 1)
                total = cnt_div + extra
                res.append(total)
        print(' '.join(map(str, res)))

solve()
