// Author: Matin Abbasi
// Date: 2025-04-24
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    ll fixed_x = -1;
    bool consistent = true;
    for (int i = 0; i < n; i++) {
        if (b[i] != -1) {
            ll curr_x = a[i] + b[i];
            if (fixed_x == -1) {
                fixed_x = curr_x;
            } else if (curr_x != fixed_x) {
                consistent = false;
            }
        }
    }

    if (!consistent) {
        cout << 0 << '\n';
        return;
    }

    if (fixed_x == -1) {
        ll lower = 0, upper = 1e18;
        for (int i = 0; i < n; i++) {
            lower = max(lower, a[i]);
            upper = min(upper, a[i] + k);
        }
        if (lower > upper) {
            cout << 0 << '\n';
        } else {
            cout << upper - lower + 1 << '\n';
        }
    } else {
        bool valid = true;
        for (int i = 0; i < n; i++) {
            if (b[i] == -1) {
                ll bi = fixed_x - a[i];
                if (bi < 0 || bi > k) {
                    valid = false;
                }
            }
        }
        cout << (valid ? 1 : 0) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
