import sys


def solve():
    t = int(sys.stdin.readline())
    for _ in range(t):
        n = int(sys.stdin.readline().strip())
        if n < 3:
            print("! 1 2 3")
            sys.stdout.flush()
            continue
        a, b, c = 1, 2, 3
        found = False
        for _ in range(75):
            print(f"? {a} {b} {c}")
            sys.stdout.flush()
            res = int(sys.stdin.readline().strip())
            if res == 0:
                print(f"! {a} {b} {c}")
                sys.stdout.flush()
                found = True
                break
            elif res == -1:
                exit()
            else:
                # Replace the third point each time
                c = res
        if not found:
            print(f"! {a} {b} {c}")
            sys.stdout.flush()
            res = sys.stdin.readline().strip()
            # If res is -1, it's wrong, but we proceed anyway


if __name__ == "__main__":
    solve()
