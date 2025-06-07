MOD = 998244353
INV_2 = 499122177  # Modular inverse of 2

def pow_mod(base, exp, mod):
    if exp < 0:
        return 0
    result = 1
    base %= mod
    while exp > 0:
        if exp & 1:
            result = (result * base) % mod
        base = (base * base) % mod
        exp >>= 1
    return result

def solve_test_case(n, m, A, B):
    # Convert A and B to binary arrays (30 bits)
    bits_A = [0] * 30
    bits_B = [0] * 30
    for i in range(29, -1, -1):
        bits_A[i] = (A >> i) & 1
        bits_B[i] = (B >> i) & 1
    
    # DP[pos][tightP][tightL][tightR_A][tightR_B]
    dp = {}
    def calc_dp(pos, tightP, tightL, tightR_A, tightR_B):
        if pos == -1:
            return 1
        state = (pos, tightP, tightL, tightR_A, tightR_B)
        if state in dp:
            return dp[state]
        
        result = 0
        max_p = bits_A[pos] if tightP else 1
        max_l = bits_B[pos] if tightL else 1
        
        for p_bit in range(max_p + 1):
            for l_bit in range(max_l + 1):
                for r_bit in range(2):
                    pr_bit = p_bit ^ r_bit
                    lr_bit = l_bit ^ r_bit
                    
                    if tightR_A and pr_bit > bits_A[pos]:
                        continue
                    if tightR_B and lr_bit > bits_B[pos]:
                        continue
                    
                    new_tightP = tightP and (p_bit == bits_A[pos])
                    new_tightL = tightL and (l_bit == bits_B[pos])
                    new_tightR_A = tightR_A and (pr_bit == bits_A[pos])
                    new_tightR_B = tightR_B and (lr_bit == bits_B[pos])
                    
                    result = (result + calc_dp(pos - 1, new_tightP, new_tightL, new_tightR_A, new_tightR_B)) % MOD
        
        dp[state] = result
        return result
    
    # Compute S
    S = calc_dp(29, 1, 1, 1, 1)
    
    # Compute N_0 * M_0
    N0_M0 = (A + 1) % MOD * (B + 1) % MOD
    
    # Compute 2^(n + m - 2) mod MOD
    power = n + m - 2
    if power >= MOD - 1:
        pow2 = 0
    else:
        pow2 = pow_mod(2, power, MOD)
    
    # Total = N_0 * M_0 + 2^(n+m-2) * (S - N_0 * M_0)
    diff = (S - N0_M0) % MOD
    if diff < 0:
        diff += MOD
    total = (N0_M0 + pow2 * diff % MOD) % MOD
    
    return total

# Read input
t = int(input())
for _ in range(t):
    n, m, A, B = map(int, input().split())
    print(solve_test_case(n, m, A, B))
