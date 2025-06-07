for _ in range(int(input())):
    s = input()
    if len(s) >= 3:
        if int(s[0]) == 1 and int(s[1]) == 0 and int(s[2]) != 0:
            if int(s[2]) == 1:
                if len(s) >= 4:
                    print("YES")
                    continue
                else:
                    print("NO")
                    continue
            print("YES")
            continue
    print("NO")
