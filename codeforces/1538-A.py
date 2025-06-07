for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    op1 = 0
    mn = min(a)
    mx = max(a)
    for i in a:
        op1 += 1
        if i == mn:
            break
    for i in reversed(a):
        op1 += 1
        if i == mx:
            break
    op2 = 0
    for i in reversed(a):
        op2 += 1
        if i == mn:
            break
    for i in a:
        op2 += 1
        if i == mx:
            break
    op3 = 0
    v = []
    for i in a:
        op3 += 1
        v.append(i)
        if mn in v and mx in v:
            break
    op4 = 0
    v = []
    for i in reversed(a):
        op4 += 1
        v.append(i)
        if mn in v and mx in v:
            break
    print(min([op1, op2, op3, op4]))
        
