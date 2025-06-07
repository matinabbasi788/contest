#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, m, k;
        cin >> n >> m >> k;
        long long lo = 1, hi = min(m, k);
        long long ans = hi;
        while (lo <= hi) {
            long long L = (lo + hi) / 2;
            long long p = m / (L + 1);
            long long r = m % (L + 1);
            long long d = p * L + min(r, L);
            if (n * d >= k) {
                ans = L;
                hi = L - 1;
            } else {
                lo = L + 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
