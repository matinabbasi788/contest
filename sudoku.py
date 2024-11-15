"""
3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 0 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0"""

l = []
lc = [] # culmn list
lq = [] # cube list
for _ in range(9):
    l.append(list(map(int, input().split(' '))))

for i in range(len(l)):
    row = []
    for j in range(len(l[i])):
        row.append(l[j][i])
    lc.append(row)
# print(lc)

for c in range(8):
    nums = [1, 2, 3, 4, 5, 6, 7, 8, 9]        
    for i in range(len(l[c])):
        for j in nums:
            if l[c][i] == 0 and j not in l[c] and j not in lc[i]:
                l[c][i] = j
                for b in range(len(lc[i])):
                     if b == 0:
                         lc[i][b] = j
                         break
print(l)    