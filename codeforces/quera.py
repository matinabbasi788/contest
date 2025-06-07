n = int(input())
ans = [i for i in range(1, n + 1)]

print(f"{' + '.join(map(str, ans))} = {sum(ans)}")
