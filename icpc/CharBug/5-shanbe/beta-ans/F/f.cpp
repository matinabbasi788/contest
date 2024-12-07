#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#define dbgarr(...)
#define LINE
#define TIME
#endif

const int N =  750 + 5;
int pr[N][N], pc[N][N];

// 0-base - interval[lx, rx][ly, ry]
class segtree_2d {
public:
    struct node {
        array<int, 4> arr;

        void apply(int v) {
            arr[3] = v;
        }
    };

    node unite(const node &a, const node &b) const {
        node res;
        int i = 3, j = 3;
        for (int k = 3; k >= 0; k--) {
            if (a.arr[i] > b.arr[j]) {
                res.arr[k] = a.arr[i];
                i--;
            }
            else {
                res.arr[k] = b.arr[j];
                j--;
            }
        }
        return res;
    }

    inline void pull_x(int x, int y) {
        tree[x][y] = unite(tree[x * 2][y], tree[x * 2 + 1][y]);
    }

    inline void pull_y(int x, int y) {
        tree[x][y] = unite(tree[x][y * 2], tree[x][y * 2 + 1]);
    }

    int n, m;
    vector<vector<node>> tree;

    template <typename M>
        void build_y(int x, int lx, int rx, int y, int ly, int ry, const vector<vector<M>> &v) {
            if (ly == ry) {
                if (lx == rx) {
                    tree[x][y].apply(v[lx][ly]);
                }
                else {
                    pull_x(x, y);
                }
                return;
            } 
            int my = (ly + ry) / 2;
            build_y(x, lx, rx, y * 2, ly, my, v);
            build_y(x, lx, rx, y * 2 + 1, my + 1, ry, v);
            pull_y(x, y);
        }

    template <typename M>
        void build_x(int x, int lx, int rx, const vector<vector<M>> &v) {
            if (lx != rx) {
                int mx = (lx + rx) / 2;
                build_x(x * 2, lx, mx, v);
                build_x(x * 2 + 1, mx + 1, rx, v);
            }
            build_y(x, lx, rx, 1, 0, m - 1, v);
        }


    node get_y(int x, int y, int ly, int ry, int lly, int rry) {
        if (lly <= ly && ry <= rry) {
            return tree[x][y];
        }
        int my = (ly + ry) / 2;
        if (my >= rry) {
            return get_y(x, y * 2, ly, my, lly, rry);
        }
        else if (my < lly) {
            return get_y(x, y * 2 + 1, my + 1, ry, lly, rry);
        }
        return unite(get_y(x, y * 2, ly, my, lly, rry), get_y(x, y * 2 + 1, my + 1, ry, lly, rry));
    }

    node get_x(int x, int lx, int rx, int llx, int rrx, int lly, int rry) {
        if (llx <= lx && rx <= rrx) {
            return get_y(x, 1, 0, m - 1, lly, rry);
        }
        int mx = (lx + rx) / 2;
        if (mx >= rrx) {
            return  get_x(x * 2, lx, mx, llx, rrx, lly, rry);
        }
        else if (mx < llx) {
            return get_x(x * 2 + 1, mx + 1, rx, llx, rrx, lly, rry);
        }
        return unite(get_x(x * 2, lx, mx, llx, rrx, lly, rry), get_x(x * 2 + 1, mx + 1, rx, llx, rrx, lly, rry));
    }

    template <typename M>
        segtree_2d(const vector<M> &v) {
            n = v.size();
            m = v[0].size();
            assert(n > 0 && m > 0);
            tree.assign(4 * n, vector<node>(4 * m));
            build_x(1, 0, n - 1, v);
        }

    node get(int llx, int rrx, int lly, int rry) {
        assert(0 <= llx && llx <= rrx && rrx <= n - 1);
        assert(0 <= lly && lly <= rry && rry <= m - 1);
        return get_x(1, 0, n - 1, llx, rrx, lly, rry);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j]; 
        }
    }

    for (int i = 0; i < n; i++) {
        pc[i][0] = -1;
        for (int j = 1; j < m; j++) {
            if (g[i][j - 1] > g[i][j]) {
                pc[i][j] = j - 1;
            }
            else {
                int k = pc[i][j - 1];
                for (; k >= 0; k--) {
                    if (g[i][k] > g[i][j]) {
                        pc[i][j] = k;
                        break;
                    }
                }
                if (k == -1) {
                    pc[i][j] = k; 
                }
            }
        }
    }

    for (int j = 0; j < m; j++) {
        pr[0][j] = -1;
        for (int i = 1; i < n; i++) {
            if (g[i - 1][j] > g[i][j]) {
                pr[i][j] = i - 1;
            }
            else {
                int k = pr[i - 1][j];
                for (; k >= 0; k--) {
                    if (g[k][j] > g[i][j]) {
                        pr[i][j] = k;
                        break;
                    }
                }
                if (k == -1) {
                    pr[i][j] = k; 
                }
            }
        }
    }

    segtree_2d sg(g);

    ll ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            vector<int> r = {i - 1}, c = {j - 1};
            int ii = i - 1, jj = j - 1;
            while (g[i][jj] < g[i][j] && pc[i][jj] != -1) {
                jj = pc[i][jj];
                c.push_back(jj);
            }
            while (g[ii][j] < g[i][j] && pr[ii][j] != -1) {
                ii = pr[ii][j];
                r.push_back(ii);
            }

            int x2 = i, y2 = j;
            for (auto x1: r) {
                for (auto y1: c) {
                    array<int, 4> a1 = {g[x1][y1], g[x1][y2], g[x2][y1], g[x2][y2]};
                    sort(a1.begin(), a1.end());
                    auto a2 = sg.get(x1, x2, y1, y2).arr;
                    if (a1 == a2) {
                        ans++;
                    }
                }
            }
        }
    }

    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
        LINE
    }
    TIME

    return 0;
}
