from math import gcd


a, b = map(int, input().split())
arr1 = list(map(int, input().split()))
arr2 = list(map(int, input().split()))
d_arr = []
for i in range(1, len(arr1)):
    d_arr.append(abs(arr1[0] - arr1[i]))
d = gcd(*d_arr)
ans_arr = []
for j in arr2:
    ans_arr.append(str(gcd(arr1[0] + j, d)))
print(' '.join(ans_arr))
