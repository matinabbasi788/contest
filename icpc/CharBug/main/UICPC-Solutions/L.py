L, j, n = map(int, input().split())
d = list(map(int, input().split()))
p = list(map(int, input().split()))
print(sum(d) + max(p) - min(p) + min(abs(j - min(p)), abs(j - max(p))))
