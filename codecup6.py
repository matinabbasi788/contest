n = list(input().split(' '))

res = [0] * int(n[0])
for i in range(int(n[0])):
    t = input()
    for j in t:
        if j not in n[1]:
            res[i] = "No"
            break
        else:
            res[i] = "Yes"
for i in res:
    print(i)