for _ in range(int(input())):
    n = int(input())
    a = input()
    b = input()
    for i in range(n):
        if (
            a[i] == "R"
            and b[i] != "R"
            or a[i] == "B"
            and b[i] not in ("B", "G")
            or a[i] == "G"
            and b[i] not in ("B", "G")
        ):
            print("NO")
            break
    else:
        print("YES")
