#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pi pair<int, int>
#define pl pair<ll, ll>
#define F first
#define S second
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define pf push_front
#define nl '\n'
#define MOD 1000000007
#define MOD1 998244353
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define fastio() ios_base::sync_with_stdio(false);cin.tie(0);
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
/**************************************************************/
#ifdef LOCAL
#include "/home/mamad/debug.h"
#else
#define debug(...) 
#define arrdebug(...) 
#define delay() 
#define LINE 
#define TIME 
#endif
/**************************************************************/

map<string, int> win, rnk;
map<string, string> lose;
vector<string> wins[20];
int mark[2000];

void solve()
{
    int k, q;
    cin >> k >> q;
    for (int i = 0; i < (1 << k) - 1; i++) {
        string s1, s2, p1, p2, zz;
        int point1, point2;
        cin >> s1 >> p1 >> zz >> p2 >> s2; 
        if (count(all(p1), '(')) {
            int pos1 = find(all(p1), '(') - p1.begin();
            int pos2 = find(all(p2), '(') - p2.begin(); 
            point1 = stoi(p1.substr(pos1 + 1, sz(p1) - pos1 - 2));
            point2 = stoi(p2.substr(pos2 + 1, sz(p2) - pos2 - 2));
        }
        else {
            point1 = stoi(p1);
            point2 = stoi(p2);
        }
        if (point1 > point2) {
            win[s1]++;
            lose[s2] = s1;
            win[s2] = win[s2];
        }
        else {
            win[s2]++;
            lose[s1] = s2;
            win[s1] = win[s1];
        }
    }
    for (auto x : win) {
        wins[x.S].pb(x.F);
    }

    rnk[wins[k][0]] = 0;
    for (int i = k - 1; i >= 0; i--) {
        for (string x : wins[i]) {
            rnk[x] = rnk[lose[x]] + (1 << i);
        }
    }


    while (q--) {
        string s1, s2, s;
        cin >> s1 >> s2; 
        int x1 = rnk[s1], x2 = rnk[s2];
        int ans = 0;
        while (x1 != x2) {
            x1 /= 2, x2 /= 2;
            ans++;
        }
        cout << ans << nl;
    }
}

int32_t main()
{
    fastio();
    solve();
    
    #ifdef LOCAL
    LINE
    TIME
    #endif
    
    return 0;
}
