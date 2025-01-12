from math import floor


a, b = map(int, input().split())
print(f"{min(a, b)} {floor((max(a,b) - min(a, b)) / 2)}")
