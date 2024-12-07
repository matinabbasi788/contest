def solve():
    n, f = map(int, input().split())
    ans = 0
    mn = 1e9  # A large number to track the minimum time
    for i in range(n):
        x, v = map(float, input().split())
        time = (f - x) / v
        if time < mn:
            mn = time
            ans = i
    print(ans + 1)

def main():
    t = 1
    # t = int(input())  # Uncomment if there are multiple test cases
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
