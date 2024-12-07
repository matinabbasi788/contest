s = input()
flg = True
for i in s[1:]:
    if i != i.upper():
        flg = False
if flg:
    if s[0] == s[0].upper():
        print(s.lower())
    else:
        print(s.capitalize())
else:
    print(s)