x = list(map(int, input()))
for i in range(len(x)):
    if i == 0 and x[i] != 9 and abs(x[i] - 9) < x[i]:
        x[i] = abs(x[i] - 9)
    elif i != 0:
        if abs(x[i] - 9) < x[i]:
            x[i] = abs(x[i] - 9)
print(''.join(list(map(str, x))))
