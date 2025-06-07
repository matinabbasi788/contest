def solve():
    n = int(input())
    a = input()
    b = input()

    if a == '0' * n:
        print("YES")
        return

    a_list = list(a)
    b_list = list(b)

    def can_crack(a_list, b_list):
        q = [(a_list, b_list)]
        visited = set()
        visited.add("".join(a_list) + "|" + "".join(b_list))

        while q:
            curr_a, curr_b = q.pop(0)

            if "".join(curr_a) == '0' * n:
                return True

            for i in range(1, n):
                new_a1 = curr_a[:]
                new_b1 = curr_b[:]
                new_a1[i], new_b1[i - 1] = new_b1[i - 1], new_a1[i]
                state1 = "".join(new_a1) + "|" + "".join(new_b1)
                if state1 not in visited:
                    q.append((new_a1, new_b1))
                    visited.add(state1)

                new_a2 = curr_a[:]
                new_b2 = curr_b[:]
                new_b2[i], new_a2[i - 1] = new_a2[i - 1], new_b2[i]
                state2 = "".join(new_a2) + "|" + "".join(new_b2)
                if state2 not in visited:
                    q.append((new_a2, new_b2))
                    visited.add(state2)
        return False

    if can_crack(a_list, b_list):
        print("YES")
    else:
        print("NO")


t = int(input())
for _ in range(t):
    solve()
