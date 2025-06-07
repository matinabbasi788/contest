def can(arr):
    for i in range(1, len(arr)):
        if arr[i-1:i+1].count(1) < 1:
            return True
    return False


for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    if arr.count(1) == n or can(arr):
        print("YES")
    else:
        print("NO")
