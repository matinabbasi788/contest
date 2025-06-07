#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Integer square root: returns largest y such that y^2 <= x
ll isqrt(ll x) {
    ll left = 0, right = 1000000; // Adjust based on max possible r_i^2
    while (left < right) {
        ll mid = left + (right - left + 1) / 2;
        if (mid * mid <= x) left = mid;
        else right = mid - 1;
    }
    return left;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> x(n), r(n);
    // Input circle centers
    for (int i = 0; i < n; i++) cin >> x[i];
    // Input radii
    for (int i = 0; i < n; i++) cin >> r[i];
    
    // Map of x-coordinates to indices of circles covering them
    map<ll, vector<int>> covered;
    for (int i = 0; i < n; i++) {
        ll left = x[i] - r[i];
        ll right = x[i] + r[i];
        // Mark all x-coordinates covered by circle i
        for (ll cur_x = left; cur_x <= right; cur_x++) {
            covered[cur_x].push_back(i);
        }
    }
    
    ll ans = 0;
    // Process each x-coordinate
    for (auto& [cur_x, vec] : covered) {
        ll max_f = LLONG_MIN;
        // Find maximum r_i^2 - (x - x_i)^2
        for (int i : vec) {
            ll d = cur_x - x[i];
            ll r2_d2 = r[i] * r[i] - d * d;
            max_f = max(max_f, r2_d2);
        }
        // If max_f >= 0, count y-values
        if (max_f >= 0) {
            ll y_max = isqrt(max_f);
            ans += 2 * y_max + 1; // Include y = 0 and symmetric y
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t; // Number of test cases
    while (t--) solve();
    return 0;
}
