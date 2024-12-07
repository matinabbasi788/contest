# Accepted

t = int(input())
while t:
    ans = 0
    t -= 1
    n, k = map(int, input().split())
    array = sorted(list(map(int, input().split())), reverse=True)
    if k in array:
        print(0)
    else:
        for i in array:
            if i > k:
                print(k)
                break 
            k -= i
        else:
            print(k)
        
