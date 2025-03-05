def can_craft_artifacts(test_cases):
    results = []
    for n, a, b in test_cases:
        deficit = 0
        surplus = 0
        for ai, bi in zip(a, b):
            if ai < bi:
                deficit += (bi - ai)
            else:
                surplus += (ai - bi)
        if deficit > surplus:
            results.append("NO")
        else:
            results.append("YES")
    return results


t = int(input())
test_cases = []

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    test_cases.append((n, a, b))

answers = can_craft_artifacts(test_cases)
print("\n".join(answers))

