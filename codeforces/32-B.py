l = list(input())
while l:
    if ''.join(l[0:2]) == "--":
        print(2, end='')
        l.pop(0)
        l.pop(0)
    elif ''.join(l[0:2]) == "-.":
        print(1, end='')
        l.pop(0)
        l.pop(0)
    elif l[0] == ".": 
        print(0, end='')
        l.pop(0)
print()
