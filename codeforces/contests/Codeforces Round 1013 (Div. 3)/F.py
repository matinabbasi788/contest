import sys
from collections import defaultdict

MOD = 998244353

def solve():
    input = sys.stdin.read().split()
    ptr = 0
    t = int(input[ptr])
    ptr += 1
    for _ in range(t):
        n, m, d = map(int, input[ptr:ptr+3])
        ptr += 3
        holds = [[] for _ in range(n+1)]
        for i in range(1, n+1):
            row = input[ptr]
            ptr += 1
            for j in range(m):
                if row[j] == 'X':
                    holds[i].append((i, j+1))
        possible = True
        for i in range(1, n+1):
            if not holds[i]:
                possible = False
                break
        if not possible:
            print(0)
            continue
        
        dp = [defaultdict(int) for _ in range(n+1)]
        for pos in holds[n]:
            dp[n][(frozenset([pos]), pos)] = 1

        for i in range(n-1, 0, -1):
            current_holds = holds[i]
            next_holds = holds[i+1]
            for state in dp[i+1]:
                used_holds, last_pos = state
                count = dp[i+1][state]
                for pos_current in current_holds:
                    dx = pos_current[0] - last_pos[0]
                    dy = pos_current[1] - last_pos[1]
                    distance_sq = dx*dx + dy*dy
                    if distance_sq > d*d:
                        continue
                    new_used_holds = set(used_holds)
                    new_used_holds.add(pos_current)
                    if len(new_used_holds) > 2:
                        continue
                    new_state = (frozenset(new_used_holds), pos_current)
                    dp[i][new_state] = (dp[i][new_state] + count) % MOD

        total = 0
        for state in dp[1]:
            used_holds, _ = state
            if len(used_holds) >= 1 and len(used_holds) <= 2:
                total = (total + dp[1][state]) % MOD
        print(total)

solve()
