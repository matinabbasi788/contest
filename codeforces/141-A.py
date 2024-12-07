guest = list(input())
residence = list(input())
pile = list(input())
a = pile[::]
for i in a:
    if i in guest:
        guest.remove(i)
        pile.remove(i)
    elif i in residence:
        residence.remove(i)
        pile.remove(i)
    else:
        print("NO")
        break
else:
    if not pile and not guest and not residence:
        print("YES")
    else:
        print("NO")