#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>

using namespace std;

class DSU {
private:
    vector<int> parent;
    vector<int> rank;
    int size;

public:
    DSU(int n) : size(n) {
        parent.resize(n);
        rank.resize(n, 1);
        reset();
    }

    void reset() {
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

struct Point {
    int x, y;
    int index;
};

struct Edge {
    int u, v;
    int min_x, max_x;
    int min_y, max_y;
};

bool isInsideAttack(int x, int y, int x1, int y1, int x2, int y2) {
    return x1 <= x && x <= x2 && y1 <= y && y <= y2;
}

int orientation(int px, int py, int qx, int qy, int rx, int ry) {
    long long val = (static_cast<long long>(qy - py) * (rx - qx)) -
                    (static_cast<long long>(qx - px) * (ry - qy));
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

bool onSegment(int px, int py, int qx, int qy, int rx, int ry) {
    return min(px, qx) <= rx && rx <= max(px, qx) &&
           min(py, qy) <= ry && ry <= max(py, qy);
}

bool segmentsIntersect(const pair<int, int>& p1, const pair<int, int>& p2,
                      const pair<int, int>& q1, const pair<int, int>& q2) {
    int o1 = orientation(p1.first, p1.second, p2.first, p2.second, q1.first, q1.second);
    int o2 = orientation(p1.first, p1.second, p2.first, p2.second, q2.first, q2.second);
    int o3 = orientation(q1.first, q1.second, q2.first, q2.second, p1.first, p1.second);
    int o4 = orientation(q1.first, q1.second, q2.first, q2.second, p2.first, p2.second);

    if (o1 != o2 && o3 != o4) return true;

    if (o1 == 0 && onSegment(p1.first, p1.second, p2.first, p2.second, q1.first, q1.second)) return true;
    if (o2 == 0 && onSegment(p1.first, p1.second, p2.first, p2.second, q2.first, q2.second)) return true;
    if (o3 == 0 && onSegment(q1.first, q1.second, q2.first, q2.second, p1.first, p1.second)) return true;
    if (o4 == 0 && onSegment(q1.first, q1.second, q2.first, q2.second, p2.first, p2.second)) return true;

    return false;
}

bool isEdgeAffected(int x1, int y1, int x2, int y2, int bx1, int by1, int bx2, int by2) {
    if (isInsideAttack(x1, y1, bx1, by1, bx2, by2) || isInsideAttack(x2, y2, bx1, by1, bx2, by2)) {
        return true;
    }

    pair<int, int> p1(x1, y1), p2(x2, y2);
    pair<int, int> left{bx1, by1}, right{bx1, by2};
    if (segmentsIntersect(p1, p2, left, right)) return true;
    left = {bx1, by2}, right = {bx2, by2};
    if (segmentsIntersect(p1, p2, left, right)) return true;
    left = {bx2, by2}, right = {bx2, by1};
    if (segmentsIntersect(p1, p2, left, right)) return true;
    left = {bx2, by1}, right = {bx1, by1};
    if (segmentsIntersect(p1, p2, left, right)) return true;

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> baseStations(n);
    vector<Point> sortedPoints(n);
    for (int i = 0; i < n; ++i) {
        cin >> baseStations[i].first >> baseStations[i].second;
        sortedPoints[i] = {baseStations[i].first, baseStations[i].second, i};
    }

    auto compareX = [](const Point& a, const Point& b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    };
    sort(sortedPoints.begin(), sortedPoints.end(), compareX);

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edges[i].u = u;
        edges[i].v = v;
        int x1 = baseStations[u].first;
        int y1 = baseStations[u].second;
        int x2 = baseStations[v].first;
        int y2 = baseStations[v].second;
        edges[i].min_x = min(x1, x2);
        edges[i].max_x = max(x1, x2);
        edges[i].min_y = min(y1, y2);
        edges[i].max_y = max(y1, y2);
    }

    vector<tuple<int, int, int, int>> attacks(k);
    for (int i = 0; i < k; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        attacks[i] = {x1, y1, x2, y2};
    }

    DSU dsu(n);

    for (const auto& attack : attacks) {
        int x1, y1, x2, y2;
        tie(x1, y1, x2, y2) = attack;
        int bx1 = min(x1, x2);
        int bx2 = max(x1, x2);
        int by1 = min(y1, y2);
        int by2 = max(y1, y2);

        vector<bool> removed(n, false);

        auto lower = lower_bound(sortedPoints.begin(), sortedPoints.end(), bx1, [](const Point& p, int x) {
            return p.x < x;
        });
        auto upper = upper_bound(sortedPoints.begin(), sortedPoints.end(), bx2, [](int x, const Point& p) {
            return x < p.x;
        });

        for (auto it = lower; it != upper; ++it) {
            if (it->y >= by1 && it->y <= by2) {
                removed[it->index] = true;
            }
        }

        dsu.reset();

        for (const auto& edge : edges) {
            int u = edge.u;
            int v = edge.v;
            if (removed[u] || removed[v]) continue;

            if (edge.max_x < bx1 || edge.min_x > bx2 || edge.max_y < by1 || edge.min_y > by2) {
                dsu.unionSets(u, v);
            } else {
                if (!isEdgeAffected(baseStations[u].first, baseStations[u].second,
                                   baseStations[v].first, baseStations[v].second,
                                   bx1, by1, bx2, by2)) {
                    dsu.unionSets(u, v);
                }
            }
        }

        vector<int> remaining;
        for (int i = 0; i < n; ++i) {
            if (!removed[i]) {
                remaining.push_back(i);
            }
        }

        if (remaining.empty()) {
            cout << "Yes\n";
            continue;
        }

        int root = dsu.find(remaining[0]);
        bool connected = true;
        for (size_t i = 1; i < remaining.size(); ++i) {
            if (dsu.find(remaining[i]) != root) {
                connected = false;
                break;
            }
        }
        cout << (connected ? "Yes" : "No") << "\n";
    }

    return 0;
}
