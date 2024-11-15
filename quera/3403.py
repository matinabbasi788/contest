# ساده تر https://quera.org/problemset/3403

l = []
for i in range(4):
    l.append(float(input()))
print(f"Sum : {format(sum(l), '.6f')}")
print(f"Average : {format(sum(l) / 4, '.6f')}")
print(f"Product : {format(l[0] * l[1] * l[2] * l[3], '.6f')}")
print(f"MAX : {format(max(l), '.6f')}")
print(f"MIN : {format(min(l), '.6f')}")
