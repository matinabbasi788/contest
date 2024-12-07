import re


"ABCDEFGHIJKLMNOPQRSTWXOUYZ"
def num_to_text(a):
    

n = int(input())
for i in range(n):
    temp = input()
    r, c = re.split(r'C', re.split(r'R', temp)[1])
    if r and c:
        print(f"{}{r}")
        