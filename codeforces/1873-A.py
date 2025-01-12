n = int(input())
for i in range(n):
    print("YES" if input() in ('abc', 'acb', 'bac', 'cba') else "NO")
