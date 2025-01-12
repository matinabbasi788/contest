ms = 0
cs = 0
for _ in range(int(input())):
    m, c = map(int, input().split())
    if m > c:
        ms += 1
    if c > m:
        cs +=1
if ms > cs:
    print("Mishka")
elif cs > ms:
    print("Chris")
else:
    print("Friendship is magic!^^")