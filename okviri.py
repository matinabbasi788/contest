string = input()

c = 1
first = True
last = False
if len(string) == 1:
    last = True
for i in string:
    if c % 3 == 1:
        print("..#..")
        print(".#.#.")
        print(f"#.{i}.#")
        print(".#.#.")
        print("..#..", end='')
    if c % 3 == 1 and not first:
        print("..#..", end='')
        print(".#.#.", end='')
        print(f"#.{i}.#", end='')
        print(".#.#.", end='')
        print("..#..", end='')
    elif c % 3 == 0:
        print(".#..")
        print("#.#.")
        print(f".{i}.#")
        print("#.#.")
        print(".#..", end='')
    elif c % 3 == 0:
        print("..*..")
        print(".*.*.")
        print(f"*.{i}.*")
        print(".*.*.")
        print("..*..", end='')
    elif c % 3 == 0 and not first:
        print("..*..", end='')
        print(".*.*.", end='')
        print(f"*.{i}.*", end='')
        print(".*.*.", end='')
        print("..*..", end='')
    if c - 1 == len(string):
        last = True
    first = False