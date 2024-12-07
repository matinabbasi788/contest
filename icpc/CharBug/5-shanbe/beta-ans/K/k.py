from collections import defaultdict

def solve():
    k, q = map(int, input().split())
    win = defaultdict(int)
    lose = {}
    wins = [[] for _ in range(20)]
    rnk = {}

    for _ in range((1 << k) - 1):
        s1, p1, zz, p2, s2 = input().split()
        
        if '(' in p1:
            pos1 = p1.index('(')
            pos2 = p2.index('(')
            point1 = int(p1[pos1 + 1: len(p1) - 1])
            point2 = int(p2[pos2 + 1: len(p2) - 1])
        else:
            point1 = int(p1)
            point2 = int(p2)
        
        if point1 > point2:
            win[s1] += 1
            lose[s2] = s1
            win[s2] = win[s2]
        else:
            win[s2] += 1
            lose[s1] = s2
            win[s1] = win[s1]
    
    for team in win:
        wins[win[team]].append(team)

    rnk[wins[k][0]] = 0
    for i in range(k - 1, -1, -1):
        for x in wins[i]:
            rnk[x] = rnk[lose[x]] + (1 << i)

    for _ in range(q):
        s1, s2 = input().split()
        x1, x2 = rnk[s1], rnk[s2]
        ans = 0
        while x1 != x2:
            x1 //= 2
            x2 //= 2
            ans += 1
        print(ans)

def main():
    solve()

if __name__ == "__main__":
    main()
