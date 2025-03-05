n = int(input())


if n > 0:
    print(n)
else:
    s = str(n)
    if int(s[-1]) > int(s[-2]):
        print(s[:-1])
    else:
        print(0 if s[:-2] + s[-1] == '-0' else s[:-2] + s[-1])
