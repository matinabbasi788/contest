#include <bits/stdc++.h>
#include <climits>
#include <cstdint>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int64_t> a(n);
        for (int64_t &x : a) cin >> x;

        int64_t ans = LLONG_MAX;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j + 1 < n && a[j + 1] == a[i]) {
                j++;
            }
            int64_t v = a[i];
            int64_t cost = v * ((int64_t)i + (int64_t)(n - 1 - j));
            ans = min(ans, cost);
            i = j + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}

