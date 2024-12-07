import re


t = input()
if re.search('.*h.*e.*l.*l.*o.*', t):
    print("YES")
else:
    print("NO")