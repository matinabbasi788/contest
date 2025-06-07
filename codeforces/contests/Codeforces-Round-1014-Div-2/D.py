def solve():
    n = int(input())
    s = input()

    counts = {'L': 0, 'I': 0, 'T': 0}
    for char in s:
        counts[char] += 1

    if len(set(counts.values())) == 1:
        print(0)
        return

    s_list = list(s)
    operations = []

    for _ in range(2 * n):
        counts = {'L': 0, 'I': 0, 'T': 0}
        for char in s_list:
            counts[char] += 1

        if len(set(counts.values())) == 1:
            print(len(operations))
            for op in operations:
                print(op)
            return

        for i in range(len(s_list) - 1):
            if s_list[i] != s_list[i + 1]:
                insert_char = None
                for char in 'LIT':
                    if char != s_list[i] and char != s_list[i + 1]:
                        insert_char = char
                        break

                s_list.insert(i + 1, insert_char)
                operations.append(i + 1)
                break
        else:
            print(-1)
            return

    print(-1)

t = int(input())
for _ in range(t):
    solve()
