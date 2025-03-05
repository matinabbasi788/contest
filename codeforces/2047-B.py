from collections import Counter


for _ in range(int(input())):
    n = int(input())
    s = input()
    cnt = Counter(s)
    max_ = max(cnt, key=cnt.get)
    cnt[max_] = float('inf')
    min_ = min(cnt, key=cnt.get)
    print(s.replace(min_, max_, 1))
