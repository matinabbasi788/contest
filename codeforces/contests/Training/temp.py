for _ in range(int(input())):
    n = bin(int(input()))[2:]
    if all([i=="0" for i in n[1:]]) or all([i=="1" for i in n[1:]]):
        print(-1)
    else:
        print(int("1" * (len(n)-1), 2))
