#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, f;
    cin >> n >> f;

    int ans = 0;
    long double mn = 1e9;
    for (int i = 0; i < n; i++) {
        long double x, v;
        cin >> x >> v;
        long double time = (f - x) / v;
        if (time < mn) {
            mn = time;
            ans = i;
        }
    }
    cout << ans + 1 << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
