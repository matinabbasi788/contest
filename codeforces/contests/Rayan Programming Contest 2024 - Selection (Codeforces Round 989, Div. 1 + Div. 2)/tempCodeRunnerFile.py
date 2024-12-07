t = int(input())  # تعداد تست کیس‌ها

for _ in range(t):
    n, k = map(int, input().split())
    
    if n % k != 0:
        print("NO")
    else:
        print("YES")
        step = n // k
        for i in range(k):
            # تولید جایگشت i‌ام
            permutation = [j for j in range(i * step + 1, (i + 1) * step + 1)]
            print(" ".join(map(str, permutation)))