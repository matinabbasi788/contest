n = int(input())
p, q = map(int, input().split())
for i in range(n - 1):
    temp = list(map(int, input().split()))
    if p < temp[0] and q > temp[1]:
        print("Happy Alex")
        break
    elif temp[1] > q:
        p = temp[0]
        q = temp[1]
else:
    print("Poor Alex")
    
