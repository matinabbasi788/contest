#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <tuple>

using namespace std;
using ll = long long;

const int MAXN = 500005;
const ll INF = 1e18;

// ساختار برای بازه‌ها
struct Interval {
    int l, r;
    ll s;
    int idx;
};

// ساختار برای Segment Tree
struct SegmentTree {
    vector<ll> tree;
    int n;

    SegmentTree(int size) : n(size) {
        tree.assign(4 * size, -INF);
    }

    void update(int idx, ll val, int node, int start, int end) {
        if (start == end) {
            tree[node] = max(tree[node], val);
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) update(idx, val, 2 * node, start, mid);
        else update(idx, val, 2 * node + 1, mid + 1, end);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    ll query(int l, int r, int node, int start, int end) {
        if (r < start || l > end) return -INF;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        ll left = query(l, r, 2 * node, start, mid);
        ll right = query(l, r, 2 * node + 1, mid + 1, end);
        return max(left, right);
    }

    void update(int idx, ll val) { update(idx, val, 1, 1, n); }
    ll query(int l, int r) { return query(l, r, 1, 1, n); }
};

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<Interval> intervals(n);
        set<int> coords;
        for (int i = 0; i < n; ++i) {
            cin >> intervals[i].l >> intervals[i].r >> intervals[i].s;
            intervals[i].idx = i;
            coords.insert(intervals[i].l);
            coords.insert(intervals[i].r);
        }

        // فشرده‌سازی مختصات
        vector<int> sorted_coords(coords.begin(), coords.end());
        map<int, int> coord_map;
        for (int i = 0; i < sorted_coords.size(); ++i) {
            coord_map[sorted_coords[i]] = i + 1;
        }
        int max_coord = sorted_coords.size();

        // ایجاد نقاط
        vector<tuple<int, int, int, ll>> points;
        for (int i = 0; i < n; ++i) {
            points.emplace_back(intervals[i].l, 1, i, intervals[i].s); // نقطه شروع
            points.emplace_back(intervals[i].r, -1, i, intervals[i].s); // نقطه پایان
        }
        sort(points.begin(), points.end());

        // Segment Tree‌ها
        SegmentTree tree_a(max_coord), tree_b(max_coord), tree_c(max_coord);
        SegmentTree tree_d(max_coord), tree_e(max_coord);

        // پیش‌پردازش بازه‌ها برای b و d
        vector<vector<tuple<int, ll, int>>> best_b(max_coord + 1);
        vector<vector<tuple<int, ll, int>>> best_d(max_coord + 1);
        for (int i = 0; i < n; ++i) {
            int r_idx = coord_map[intervals[i].r];
            best_b[r_idx].emplace_back(intervals[i].l, intervals[i].s, i);
            best_d[r_idx].emplace_back(intervals[i].l, intervals[i].s, i);
        }

        ll max_beauty = -1;

        // پیمایش نقاط
        for (auto [x, type, idx, s] : points) {
            int l = intervals[idx].l, r = intervals[idx].r;
            int l_idx = coord_map[l], r_idx = coord_map[r];

            if (type == 1) { // نقطه شروع
                tree_a.update(l_idx, s);
                tree_c.update(l_idx, s);
                tree_e.update(l_idx, s);
            } else { // نقطه پایان
                tree_b.update(r_idx, s);
                tree_d.update(r_idx, s);

                // بررسی برای b
                for (auto [lb, sb, ib] : best_b[r_idx]) {
                    int lb_idx = coord_map[lb];
                    int rb = intervals[ib].r;

                    // پیدا کردن a با l_a < l_b
                    ll sa = tree_a.query(1, lb_idx - 1);
                    if (sa == -INF) continue;

                    // بررسی r_a < r_b
                    for (int ra = lb + 1; ra < rb; ++ra) {
                        if (!coord_map.count(ra)) continue;
                        int ra_idx = coord_map[ra];
                        ll sa2 = tree_a.query(1, lb_idx - 1);
                        if (sa2 == -INF) continue;

                        // پیدا کردن c با l_c < r_b
                        ll sc = tree_c.query(1, coord_map[rb] - 1);
                        if (sc == -INF) continue;

                        // پیدا کردن d با r_b < l_d
                        for (int ld = rb + 1; coord_map.count(ld); ++ld) {
                            int ld_idx = coord_map[ld];
                            // بررسی r_d < r_c
                            for (auto [ld2, sd, id] : best_d[coord_map[intervals[id].r]]) {
                                if (rb < ld2) {
                                    // پیدا کردن e با l_d < l_e < r_d
                                    ll se = tree_e.query(ld_idx + 1, coord_map[intervals[id].r] - 1);
                                    if (se == -INF) continue;
                                    ll beauty_sum = sa2 + sb + sc + sd + se;
                                    max_beauty = max(max_beauty, beauty_sum);
                                }
                            }
                        }
                    }
                }
            }
        }

        cout << (max_beauty == -1 ? -1 : max_beauty) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
