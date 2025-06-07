required = [3, 1, 2, 1, 0, 1, 0, 0, 0, 0]  # 0:3, 1:1, 2:2, 3:1, 5:1

t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    count = [0] * 10

    found = False
    for k in range(n):
        count[a[k]] += 1
        if all(count[d] >= required[d] for d in range(10)):
            print(k + 1)  # k is 0-based, output needs 1-based position
            found = True
            break

    if not found:
        print(0)
