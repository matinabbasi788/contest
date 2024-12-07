def solve():
    n = int(input())
    ans = 0
    for _ in range(n):
        x = int(input())
        ans += x
    print(ans)

def main():
    t = 1
    # t = int(input())  # Uncomment if there are multiple test cases
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
