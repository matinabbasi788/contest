a = [1, 2, 3, 4, 5, 6, 7, 8, 9]


def solve(x):
    for i in range(1, 10):
        if i == x:
            return i
    for i in range(1, 10):
        for j in range(i+1, 10):
            if i + j == x:
                return f"{i}{j}"
    for i in range(1, 10):
        for j in range(i+1, 10):
            for k in range(j+1, 10):
                if i + j + k == x:
                    return f"{i}{j}{k}"
    for i in range(1, 10):
        for j in range(i+1, 10):
            for k in range(j+1, 10):
                for l in range(k+1, 10):
                    if i + j + k + l == x:
                        return f"{i}{j}{k}{l}"
    for i in range(1, 10):
        for j in range(i+1, 10):
            for k in range(j+1, 10):
                for l in range(k+1, 10):
                    for m in range(l+1, 10):
                        if i + j + k + l + m == x:
                            return f"{i}{j}{k}{l}{m}"
    for i in range(1, 10):
        for j in range(i+1, 10):
            for k in range(j+1, 10):
                for l in range(k+1, 10):
                    for m in range(l+1, 10):
                        for n in range(m+1, 10):
                            if i + j + k + l + m + n == x:
                                return f"{i}{j}{k}{l}{m}{n}"
    for i in range(1, 10):
        for j in range(i+1, 10):
            for k in range(j+1, 10):
                for l in range(k+1, 10):
                    for m in range(l+1, 10):
                        for n in range(m+1, 10):
                            for o in range(n+1, 10):
                                if i + j + k + l + m + n + o == x:
                                    return f"{i}{j}{k}{l}{m}{n}{o}"
    for i in range(1, 10):
        for j in range(i+1, 10):
            for k in range(j+1, 10):
                for l in range(k+1, 10):
                    for m in range(l+1, 10):
                        for n in range(m+1, 10):
                            for o in range(n+1, 10):
                                for p in range(o+1, 10):
                                    if i + j + k + l + m + n + o + p == x:
                                        return f"{i}{j}{k}{l}{m}{n}{o}{p}"
    for i in range(1, 10):
        for j in range(i+1, 10):
            for k in range(j+1, 10):
                for l in range(k+1, 10):
                    for m in range(l+1, 10):
                        for n in range(m+1, 10):
                            for o in range(n+1, 10):
                                for p in range(o+1, 10):
                                    for q in range(p+1, 10):
                                        if i + j + k + l + m + n + o + p + q == x:
                                            return f"{i}{j}{k}{l}{m}{n}{o}{p}{q}"
    return -1



for _ in range(int(input())):
    print(solve(int(input())))
