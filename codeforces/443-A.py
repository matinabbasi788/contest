a = input()
if a == "{}":
    print(0)
else:
    b = a[1:-1].rstrip()
    print(len(set(b.split(', '))))