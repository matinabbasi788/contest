# صدگان خسته https://quera.org/problemset/3406


a = input()
b = input()
ar = int(a[::-1])
br = int(b[::-1])
a = int(a)
b = int(b)

if ar > br:
    print(f"{b} < {a}")
elif br > ar:
    print(f"{a} < {b}")
else:
    print(f"{a} = {b}")