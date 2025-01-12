N = 30
M = 30
K = min(N * M, 50) 

dp = [
        [
            [
                float('inf') for i in range(N)
                ],
            [
                float('inf') for i in range(M)
                ],
            [
                float('inf') for i in range(K)
                ]
            ]
        ]
print(dp)

for i in range(int(input())):
    n, m, k = map(int, input().split())



