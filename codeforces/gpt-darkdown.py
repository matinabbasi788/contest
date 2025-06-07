import sys


def main():
    k = int(sys.stdin.readline().strip())

    chunks = [sys.stdin.readline().strip() for _ in range(k)]

    t = list(map(int, sys.stdin.readline().strip().split()))

    # Compute cumulative lengths
    cumsum = [0] * (k + 1)
    for i in range(k):
        cumsum[i + 1] = cumsum[i] + len(chunks[i])
    n = cumsum[k]

    # Build time array
    time = [0] * n
    for i in range(k):
        for j in range(cumsum[i], cumsum[i + 1]):
            time[j] = t[i]

    # Concatenate chunks
    message = ''.join(chunks)

    # Parse rendered text
    rendered_times = []
    state = "normal"
    inside_inline_code = False
    i = 0
    while i < n:
        if inside_inline_code:
            if message[i] == '`':
                inside_inline_code = False
            else:
                rendered_times.append(time[i])
        else:
            if message[i] == '`':
                inside_inline_code = True
            elif message[i] == '\\' and i + 1 < n:
                rendered_times.append(max(time[i], time[i + 1]))
                i += 1
            elif message[i] == ':':
                j = message.find(':', i + 1)
                rendered_times.append(time[j])
                i = j
            elif message[i] == '(' and state == "normal":
                state = "bold"
            elif message[i] == '[' and state == "normal":
                state = "italic"
            elif message[i] == ')' and state == "bold":
                state = "normal"
            elif message[i] == ']' and state == "italic":
                state = "normal"
            else:
                rendered_times.append(time[i])
        i += 1

    # Compute earliest start time
    m = len(rendered_times)
    s = float('-inf')
    for i in range(m):
        s = max(s, rendered_times[i] - i)

    print(s)


if __name__ == "__main__":
    main()

