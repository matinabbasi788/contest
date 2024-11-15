from collections import defaultdict


def isRectangleCover(rectangles):
    if n <= 0:
        return False
    left = min(rec[0] for rec in rectangles)
    bottom = min(rec[1] for rec in rectangles)
    right = max(rec[2] for rec in rectangles)
    top = max(rec[3] for rec in rectangles)

    points = defaultdict(int)
    for l, b, r, t in rectangles:
        for p, q in zip(((l, b), (r, b), (l, t), (r, t)), (1, 2, 4, 8)):
            if points[p] & q:
                return False
            points[p] |= q

    for px, py in points:
        if left < px < right or bottom < py < top:
            if points[(px, py)] not in (3, 5, 10, 12, 15):
                return False

    return True


n = int(input())
list1 = []
for i in range(n):
    list1.append(input().split(','))
    
if isRectangleCover(list1):
    print('true')
else:
    print('false')