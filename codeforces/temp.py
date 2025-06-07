from heapq import heappush, heappop
from collections import defaultdict

def solve():
    t = int(input())
    
    for _ in range(t):
        n = int(input())
        intervals = []
        for i in range(n):
            l, r, s = map(int, input().split())
            intervals.append((l, r, s))
        
        # فشرده‌سازی مختصات
        coords = set()
        for l, r, _ in intervals:
            coords.add(l)
            coords.add(r)
        coords = sorted(coords)
        coord_map = {x: i + 1 for i, x in enumerate(coords)}
        max_coord = len(coords)
        
        # ایجاد نقاط
        points = []
        for i, (l, r, s) in enumerate(intervals):
            points.append((l, 1, i, s))  # نقطه شروع
            points.append((r, -1, i, s))  # نقطه پایان
        points.sort()
        
        # داده‌ساختارها برای بازه‌های فعال
        active_a = []  # max-heap برای a (بر اساس زیبایی)
        active_b = []  # max-heap برای b (بر اساس زیبایی)
        active_c = []  # max-heap برای c (بر اساس زیبایی)
        active_d = []  # max-heap برای d (بر اساس زیبایی)
        active_e = []  # max-heap برای e (بر اساس زیبایی)
        
        # برای بررسی سریع شرایط
        best_a = defaultdict(list)  # l_a -> [(r_a, s_a, idx)]
        best_b = defaultdict(list)  # r_b -> [(l_b, s_b, idx)]
        best_c = defaultdict(list)  # l_c -> [(r_c, s_c, idx)]
        best_d = defaultdict(list)  # l_d -> [(r_d, s_d, idx)]
        best_e = defaultdict(list)  # l_e -> [(r_e, s_e, idx)]
        
        max_beauty = -1
        
        # پیش‌پردازش بازه‌ها
        for i, (l, r, s) in enumerate(intervals):
            l_idx = coord_map[l]
            r_idx = coord_map[r]
            best_a[l_idx].append((r, s, i))
            best_b[r_idx].append((l, s, i))
            best_c[l_idx].append((r, s, i))
            best_d[l_idx].append((r, s, i))
            best_e[l_idx].append((r, s, i))
        
        # پیمایش نقاط
        for x, point_type, idx, beauty in points:
            l, r, s = intervals[idx]
            l_idx = coord_map[l]
            r_idx = coord_map[r]
            
            if point_type == 1:  # نقطه شروع
                heappush(active_a, (-s, l, r, idx))
                heappush(active_c, (-s, l, r, idx))
                heappush(active_e, (-s, l, r, idx))
            else:  # نقطه پایان
                heappush(active_b, (-s, l, r, idx))
                heappush(active_d, (-s, l, r, idx))
                
                # حذف بازه‌های غیرفعال
                while active_a and intervals[active_a[0][3]][1] < x:
                    heappop(active_a)
                while active_b and intervals[active_b[0][3]][1] < x:
                    heappop(active_b)
                while active_c and intervals[active_c[0][3]][1] < x:
                    heappop(active_c)
                while active_d and intervals[active_d[0][3]][1] < x:
                    heappop(active_d)
                while active_e and intervals[active_e[0][3]][1] < x:
                    heappop(active_e)
                
                # بررسی برای ۵-تایی المپیکی
                for _, la, ra, ia in active_a:
                    for lb, sb, ib in best_b[r_idx]:
                        if la < lb < ra < intervals[ib][1]:  # شرط a و b
                            for lc, rc, sc, ic in best_c[l_idx]:
                                if lc < intervals[ib][1] < rc:  # شرط c نسبت به b
                                    for ld, rd, sd, id_ in best_d[l_idx]:
                                        if intervals[ib][1] < ld < rc:  # شرط c نسبت به d
                                            for le, re, se, ie in best_e[l_idx]:
                                                if ld < le < rd < re:  # شرط d و e
                                                    beauty_sum = intervals[ia][2] + sb + sc + sd + se
                                                    max_beauty = max(max_beauty, beauty_sum)
        
        print(max_beauty if max_beauty != -1 else -1)

solve()
