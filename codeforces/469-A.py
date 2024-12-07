n = int(input())
p = list(map(int, input().split()))[1:]
q = list(map(int, input().split()))[1:]
if len(set(p + q)) == n:
    print("I become the guy.")
else:
    print("Oh, my keyboard!")