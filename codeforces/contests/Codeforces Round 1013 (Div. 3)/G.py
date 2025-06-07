def maximum_power(s, k):
    # Gleb می‌تواند با قدرت اولیه خودش حرکت کند.
    # ابتدا تعداد ضربات لازم بدون چرخش را محاسبه می‌کنیم.
    if s % k == 0:
        return k  # در صورتی که دقیقا با ضربات کامل رسید
    else:
        # وقتی Gleb نیاز به چرخش داشته باشد
        # تعداد ضربات پارو باید را طوری تقسیم کنیم که از قدرت بهینه استفاده کند.
        return s % k

def main():
    t = int(input())  # تعداد تست‌ها
    for _ in range(t):
        s, k = map(int, input().split())
        print(maximum_power(s, k))

# تست کد
if __name__ == "__main__":
    main()

