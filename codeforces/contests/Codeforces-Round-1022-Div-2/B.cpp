#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int bitcount(ll x) {
    return __builtin_popcountll(x);
}

ll fixForTwo(ll r) {
    if (r == 0) return 2;
    if (bitcount(r) >= 2) return r;
    for (int i = 0; i < 31; i++) {
        if (!((r >> i) & 1)) {
            ll shift = 1LL << i;
            return r + 2 * shift;
        }
    }
    return r + 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        ll n, x;
        cin >> n >> x;

        if (n == 1) {
            cout << (x > 0 ? x : -1) << '\n';
            continue;
        }

        ll res = LLONG_MAX;
        int maxK = min<ll>(n, 30);

        for (int k = 1; k <= maxK; k++) {
            int toggle = (n - k) & 1;
            ll r = x ^ toggle;
            ll sum = LLONG_MAX;

            if (k == 1) {
                if (r > 0) sum = r;
            } else if (k == 2) {
                sum = fixForTwo(r);
            } else {
                if (r == 0 && k == 3) {
                    sum = 6;
                } else if (bitcount(r) >= k) {
                    sum = r;
                }
            }

            if (sum < LLONG_MAX) {
                res = min(res, (n - k) + sum);
            }
        }

        cout << (res == LLONG_MAX ? -1 : res) << '\n';
    }

    return 0;
}
