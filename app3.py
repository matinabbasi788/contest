n = int(input())
l = []
lh = []
k = 0
for i in range(n):
    l.append(input().split(' '))
r =[]
for i in range(n):
    sol = []
    for j in range(n):
        sol.append('0')
    r.append(sol)        

for j in range(n):
    for i in range(n):
        if j == 0 and i == 0: # first corner
            lh.append([l[j][i+1], l[j+1][i], l[j+1][i+1]])
        elif j == n-1 and i == 0: # second corner
            lh.append([l[j-1][i], l[j-1][i+1], l[j][i+1]])
        elif j == 0 and i == n-1: # third corner
            lh.append([l[j][i-1], l[j+1][i-1], l[j+1][i]])
        elif j == n-1 and i == n-1: # fourth corner
            lh.append([l[j-1][i], l[j-1][i-1], l[j][i-1]])
        elif j == 0: # first row
            lh.append([l[j+1][i-1], l[j+1][i], l[j+1][i+1], l[j][i-1], l[j][i+1]])
        elif i == 0: # first cullemn
            lh.append([l[j-1][i], l[j-1][i+1], l[j][i+1], l[j+1][i], l[j+1][i+1]])
        elif j == n-1: # last row
            lh.append([l[j-1][i-1], l[j-1][i], l[j-1][i+1], l[j][i-1], l[j][i+1]])
        elif i == n-1:
            lh.append([l[j-1][i], l[j-1][i-1], l[j][i-1], l[j+1][i], l[j+1][i-1]])
        else:
            lh.append([l[j][i+1], l[j][i-1], l[j-1][i-1],
                    l[j-1][i], l[j-1][i+1], l[j+1][i-1],
                    l[j+1][i], l[j+1][i+1]])
        if l[j][i] == '1' and lh[k].count('1') < 2:
            r[j][i] = '0'
        elif l[j][i] == '1' and (lh[k].count('1') == 2 or lh[k].count('1') == 3):
                r[j][i] = '1'
        elif l[j][i] == '1' and lh[k].count('1') > 3:
            r[j][i] = '0'
        elif l[j][i] == '0' and lh[k].count('1') == 3:
            r[j][i] = '1'
        k += 1
for i in r:
    print(" ".join(i))