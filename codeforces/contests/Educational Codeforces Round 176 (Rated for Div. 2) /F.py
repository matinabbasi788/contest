import bisect


def compress(arr):
    sorted_unique = sorted(set(arr))
    return {v: i+1 for i, v in enumerate(sorted_unique)}


def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    idx = 0
    t = int(data[idx])
    idx += 1
    results = []

    for _ in range(t):
        n = int(data[idx])
        idx += 1
        a = list(map(int, data[idx:idx+n]))
        idx += n

        if n == 0:
            results.append(0)
            continue

        # Coordinate compression for a
        compressed = compress(a)
        max_val = len(compressed)
        a_compressed = [compressed[x] for x in a]

        # Compute left array
        left = [1] * n
        fenwick = [0] * (max_val + 2)

        def update(pos, val):
            while pos <= max_val:
                if val > fenwick[pos]:
                    fenwick[pos] = val
                else:
                    break
                pos += pos & -pos

        def query(pos):
            res = 0
            while pos > 0:
                res = max(res, fenwick[pos])
                pos -= pos & -pos
            return res

        for i in range(n):
            current = a_compressed[i]
            q = query(current - 1)
            left[i] = q + 1
            update(current, left[i])

        # Compute right array
        right = [1] * n
        fenwick = [0] * (max_val + 2)

        def update_r(pos, val):
            while pos > 0:
                if val > fenwick[pos]:
                    fenwick[pos] = val
                else:
                    break
                pos -= pos & -pos

        def query_r(pos):
            res = 0
            while pos <= max_val:
                res = max(res, fenwick[pos])
                pos += pos & -pos
            return res

        for i in range(n-1, -1, -1):
            current = a_compressed[i]
            q = query_r(current + 1)
            right[i] = q + 1
            update_r(current, right[i])

        max_len = max(left[i] + right[i] - 1 for i in range(n))
        results.append(max_len)

    sys.stdout.write('\n'.join(map(str, results)) + '\n')


if __name__ == '__main__':
    main()
