n, t = map(int, input().split())
kids = input()
for i in range(t):
    kids = kids.replace('BG', 'GB')
print(kids)