n = int(input())
l = list(map(int, input().split()))
# l.sort(reverse=True)
p1 = l[:len(l)//4]
p2 = l[len(l)//4:len(l)//2]
p3 = l[len(l)//2:len(l)//2 + len(l)//4]
p4 = l[len(l)//2 + len(l)//4:]
print(abs(max(p4) - min(p1)))