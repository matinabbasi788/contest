from math import ceil

w, y = map(int, input().split())
d = 7 - max(w, y)
division = 6
for i in range(6):
    if d % d == 0 and division % d == 0:
        division /= d
        d /= d
if d % 2 == 0 and division % 2 == 0:
    d /= 2
    division /= 2
        
print(f"{int(d)}/{int(division)}")
