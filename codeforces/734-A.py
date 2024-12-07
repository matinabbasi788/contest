n = int(input())
t = input()
if t.count("A") > t.count("D"):
    print("Anton")
elif t.count("D") > t.count("A"):
    print("Danik")
else:
    print("Friendship")