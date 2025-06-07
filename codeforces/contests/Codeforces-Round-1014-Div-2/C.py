def solve():
    n = int(input())
    a = list(map(int, input().split()))
    
    odd_count = sum(1 for x in a if x % 2 != 0)
    
    if odd_count % 2 == 0:
        print(max(a))
    else:
        print(max(a) + 1 if max(a) == sum(a) // n and sum(a)%n !=0 else max(a))

t = int(input())
for _ in range(t):
    solve()
