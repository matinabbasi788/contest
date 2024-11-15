from collections import defaultdict, deque

def min_guests_to_invite(n, guests):
    # ساخت گراف
    graph = defaultdict(list)
    
    # ساخت دیکشنری‌های قد و وزن
    height_map = defaultdict(list)
    weight_map = defaultdict(list)
    
    for i, (h, w) in enumerate(guests):
        height_map[h].append(i)
        weight_map[w].append(i)
    
    # اضافه کردن یال‌ها
    for indices in height_map.values():
        for i in range(1, len(indices)):
            graph[indices[i]].append(indices[i - 1])
            graph[indices[i - 1]].append(indices[i])
    
    for indices in weight_map.values():
        for i in range(1, len(indices)):
            graph[indices[i]].append(indices[i - 1])
            graph[indices[i - 1]].append(indices[i])
    
    # بررسی دو بخشی بودن گراف و پیدا کردن مؤلفه‌های دو بخشی نشده
    visited = [-1] * n  # -1 یعنی بازدید نشده، 0 و 1 رنگ‌های دو بخش هستند
    min_new_guests = 0
    
    for i in range(n):
        if visited[i] == -1:
            queue = deque([i])
            visited[i] = 0
            is_bipartite = True
            
            while queue:
                node = queue.popleft()
                for neighbor in graph[node]:
                    if visited[neighbor] == -1:
                        visited[neighbor] = 1 - visited[node]
                        queue.append(neighbor)
                    elif visited[neighbor] == visited[node]:
                        is_bipartite = False
            
            if not is_bipartite:
                min_new_guests += 1
    
    return min_new_guests

# نمونه ورودی
n = int(input())
guests = []
for i in range(n):
    temp = list(map(int, input().split()))
    guests.append([temp[0], temp[1]])

# چاپ نتیجه
print(min_guests_to_invite(n, guests))