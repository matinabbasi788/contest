def solve_haystacks(test_cases):
    results = []
    
    for n, haystacks in test_cases:
        # مرتب‌سازی بر اساس b_i
        haystacks.sort(key=lambda x: x[1])
        
        total_haybales = sum(a for a, b in haystacks)  # مجموع کاه‌ها
        total_limit = sum(b for a, b in haystacks)  # مجموع محدودیت‌ها
        
        # اگر مجموع کاه‌ها از مجموع محدودیت‌ها کمتر است، امکان خالی کردن وجود ندارد
        if total_haybales < total_limit:
            results.append(-1)
            continue
        
        moves = 0
        for i in range(n):
            a_i, b_i = haystacks[i]
            if a_i > b_i:
                # اگر مقدار کاه این انبار بیشتر از محدودیتش باشد، مازاد آن باید جابه‌جا شود
                moves += a_i - b_i
                total_haybales -= a_i - b_i  # از مجموع کاه‌های باقی‌مانده کم می‌شود
            else:
                total_haybales -= a_i  # از مجموع کاه‌های باقی‌مانده کم می‌شود
        
        results.append(moves)
    
    return results

# پردازش ورودی
t = int(input())
test_cases = []

for _ in range(t):
    n = int(input())
    haystacks = [tuple(map(int, input().split())) for _ in range(n)]
    test_cases.append((n, haystacks))

# حل مسئله و چاپ خروجی
answers = solve_haystacks(test_cases)
print("\n".join(map(str, answers)))

