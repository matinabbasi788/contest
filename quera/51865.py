# بهداشت و سلامت https://quera.org/problemset/51865

X = int(input())
N = int(input())
if N == 0:
    print(20)
elif N == 7:
    print(X)
else:
    print(max(0, X-N))