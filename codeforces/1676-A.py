for _ in range(int(input())):
    s = input()
    if sum(list(map(int, s[:3]))) == sum(list(map(int, s[3:]))):
        print("YES")
    else:
        print("NO")