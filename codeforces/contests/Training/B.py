import heapq

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    if n == 1:
        print(a[0])
        continue
    # Use a max-heap by inserting negative values
    heap = []
    for num in a:
        heapq.heappush(heap, -num)
    while len(heap) > 1:
        largest = -heapq.heappop(heap)
        second_largest = -heapq.heappop(heap)
        # The new x must be less than largest + second_largest
        # To maximize x, set x = largest + second_largest - 1
        x = largest + second_largest - 1
        heapq.heappush(heap, -x)
    print(-heap[0])
