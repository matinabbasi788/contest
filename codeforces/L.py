l, j, n = map(int ,input().split())
l_pol = sum(list(map(int, input().split())))
m_pol = sorted(list(map(int, input().split())))

for i in range(len(m_pol)):
    if j == 0:
        print(l_pol + abs(j - max(m_pol)))
        break
    elif m_pol[i] >= j:
        print(l_pol + abs(j - max(m_pol)) + abs(min(m_pol) - max(m_pol)))
        break
else:
    print(l_pol + abs(j - min(m_pol)) + abs(max(m_pol) - min(m_pol)))
