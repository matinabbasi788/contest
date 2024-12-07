n = int(input())
ans = 0
string = input()
for i in range(len(string) - 1):
    if string[i] == string[i+1]:
        ans += 1
print(ans)