t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    m_e = k - 1
    if n % 2 == 0:
        ans = (n + m_e - 1) / m_e
    else:
        ans = 1 + ((n - k) + m_e - 1) / m_e
    print(int(ans))
