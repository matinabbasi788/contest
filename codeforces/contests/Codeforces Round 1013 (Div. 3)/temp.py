import math

MOD = 998244353

# محاسبه فاصله اقلیدسی بین دو هولدر
def euclidean_distance(x1, y1, x2, y2):
    return math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)

# محاسبه تعداد مسیرهای معتبر
def calculate_routes(n, m, d, grid):
    # هولدرهای موجود در هر سطح
    holds = [[] for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if grid[i][j] == 'X':
                holds[i].append(j)
    
    # اگر هیچ هولدری در سطح n-1 نباشد، نتیجه برابر صفر است
    if len(holds[n-1]) == 0:
        return 0
    
    # جدول DP برای شمارش مسیرها
    dp = [[0] * len(holds[i]) for i in range(n)]
    
    # از پایین‌ترین سطح شروع می‌کنیم
    for i in range(len(holds[n-1])):
        dp[n-1][i] = 1

    # از سطح n-2 به بالا حرکت می‌کنیم
    for i in range(n-2, -1, -1):
        for j in range(len(holds[i])):
            for k in range(len(holds[i+1])):
                # بررسی فاصله بین دو هولدر
                dist = euclidean_distance(i, holds[i][j], i+1, holds[i+1][k])
                if dist <= d:
                    dp[i][j] = (dp[i][j] + dp[i+1][k]) % MOD
    
    # جمع کردن نتایج برای سطح اول (سطح 1)
    result = 0
    for i in range(len(holds[0])):
        result = (result + dp[0][i]) % MOD
    
    return result

def main():
    t = int(input())  # تعداد تست‌ها
    for _ in range(t):
        n, m, d = map(int, input().split())  # n: تعداد سطوح، m: تعداد بخش‌ها در هر سطح، d: فاصله بازو
        grid = [input().strip() for _ in range(n)]  # ماتریس نمایان‌گر سطح‌ها
        
        result = calculate_routes(n, m, d, grid)
        print(result)

if __name__ == "__main__":
    main()

