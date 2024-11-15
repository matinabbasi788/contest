n = int(input()) + 1


while True:
    if str(n).count(str(0)) > 1 or str(n).count(str(1)) > 1 or str(n).count(str(2)) > 1 or\
        str(n).count(str(3)) > 1 or str(n).count(str(4)) > 1 or str(n).count(str(5)) > 1 or\
        str(n).count(str(6)) > 1 or str(n).count(str(7)) > 1 or str(n).count(str(8)) > 1 or\
            str(n).count(str(9)) > 1:
            n += 1
    else:
        break
print(n)
        