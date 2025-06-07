def solve(m, s):
    if m == 1 and s == 0:
        return "0 0"
    if (s == 0 and m > 1) or s > 9*m or (s < 1 and m >= 1):
        return "-1 -1"

    min_num = ['0'] * m
    remaining_sum = s

    min_num[0] = '1'
    remaining_sum -= 1

    for i in range(m-1, -1, -1):
        if remaining_sum > 9:
            min_num[i] = '9'
            remaining_sum -= 9
        else:
            min_num[i] = str(remaining_sum + int(min_num[i]))
            remaining_sum = 0
            break

    max_num = ['0'] * m
    remaining_sum = s

    for i in range(m):
        if remaining_sum >= 9:
            max_num[i] = '9'
            remaining_sum -= 9
        else:
            max_num[i] = str(remaining_sum)
            remaining_sum = 0
            break

    return ''.join(min_num) + ' ' + ''.join(max_num)


m, s = map(int, input().split())
print(solve(m, s))
