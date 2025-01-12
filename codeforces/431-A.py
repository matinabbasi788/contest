array = list(map(int, input().split()))
ans = 0
for i in input():
    ans += array[int(i)-1]
print(ans) 
