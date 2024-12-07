def longest_common_substring(s1, s2):
    m, n = len(s1), len(s2)
    max_length = 0
    ending_index = 0

    # ایجاد جدول
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    
    # پر کردن جدول
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if s1[i - 1] == s2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
                if dp[i][j] > max_length:
                    max_length = dp[i][j]
                    ending_index = i  # ذخیره موقعیت انتهای زیررشته
            else:
                dp[i][j] = 0

    # استخراج بزرگ ترین زیررشته متوالی مشترک
    if max_length == 0:
        return ""  # هیچ زیررشته مشترکی وجود ندارد

    start = ending_index - max_length
    return s1[start:ending_index]

# مثال
str1 = input()
str2 = input()
result = longest_common_substring(str1, str2)

if result == "":
    print(-1)  # در صورتی که زیررشته‌ای پیدا نشود
else:
    index1 = str1.find(result)
    index2 = str2.find(result)

    # اتصال رشته‌های غیرمشترک
    s1 = str1[:index1 - 1]
    s2 = str2[index2:]
    print(s1 + s2)  # چاپ رشته‌ی نهایی
