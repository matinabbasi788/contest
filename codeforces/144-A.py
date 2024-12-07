n = int(input())
array = list(map(int, input().split()))
r = array.index(max(array))
l = len(array) - 1 - array[::-1].index(min(array))
if r > l:
    print(r + (n - 1 - l) - 1 )
else:
    print(r + (n - 1 - l))