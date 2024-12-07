n = int(input())
cap = 0
lcap = 0
for i in range(n):
    temp = list(map(int, input().split()))
    lcap -= temp[0]
    lcap += temp[1]
    cap = max(lcap, cap)
print(cap)