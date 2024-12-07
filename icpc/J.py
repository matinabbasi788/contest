from collections import defaultdict

def max_sum_with_constraints(n, k, row1, row2):
    # شمارش تعداد تکرار هر عدد در دو ردیف
    count = defaultdict(int)
    for num in row1:
        count[num] += 1
    for num in row2:
        count[num] += 1

    # لیست اعداد و تعداد دفعات آن‌ها
    numbers = list(count.items())  # [(number, frequency)]
    numbers.sort(key=lambda x: -x[0])  # مرتب‌سازی بر اساس مقدار (نزولی)

    # انتخاب اعداد به نحوی که حداقل k عدد متمایز باقی بماند
    remaining_numbers = 0
    remaining_sum = 0
    for value, freq in numbers:
        if remaining_numbers >= k:
            break
        remaining_numbers += 1
        remaining_sum += value * min(freq, 2)  # حداکثر دو بار می‌توان از یک عدد استفاده کرد

    return remaining_sum

# ورودی گرفتن
n, k = map(int, input().split())
row1 = list(map(int, input().split()))
row2 = list(map(int, input().split()))

# محاسبه و چاپ خروجی
result = max_sum_with_constraints(n, k, row1, row2)
print(result)