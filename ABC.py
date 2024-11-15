l = [0] * 3
orders = [0] * 3
sorted_orders = [0] * 3
input1 = input()
input2 = input()
for i in range(3):
    l[i] = input1[i]
    orders[i], sorted_orders[i] = input2[i], input2[i]
l.sort(reverse=True)
sorted_orders.sort(reverse=True)
dic = dict(zip(sorted_orders, l))
for i in orders:
    print(dic[i], end=' ')
