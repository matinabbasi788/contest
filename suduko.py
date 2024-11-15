"""        
3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 0 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0
"""

l = []
for i in range(9):
    l.append(list(map(int, input().split(' '))))
count = [0]*10
for i in l:
    for j in i:
        count[j] += 1
m = max(count[1:])
index = count.index(m)
row = [0]*10
column = [0]*10
print(index)
c = 0
# for i in l:
#     flag = False
#     c += 1
#     for j in i:
#         if index == j:
#             flag = True
#             break
#     if  not flag:
#         row[c] = '*'

# print(row)-
index = 3
c1 = 0
for i in l:
    flag = False
    c2 = 0
    for j in i:
        lk = l[c1][c2]
        c2 += 1
        if index == lk:
            flag = True
            break
    if  not flag:
        column[c] = '*'    
    c1 += 1
print(column)
