#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
long long freq[MAXN], cum[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for (int i = 0; i < m; i++) {
            cin >> a[i];
        }
        
        // Initialize frequency array
        for (int i = 0; i <= n; i++) {
            freq[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            if (a[i] <= n) { // Since a_i ≤ n is guaranteed
                freq[a[i]]++;
            }
        }
        
        // Compute cumulative sums: cum[s] = number of colors with a_i ≥ s
        cum[n + 1] = 0;
        for (int s = n; s >= 0; s--) {
            cum[s] = cum[s + 1] + freq[s];
        }
        
        // Calculate total number of ways
        long long ans = 0;
        for (int k = 1; k <= n - 1; k++) {
            int m = max(k, n - k);
            ans += cum[k] * cum[n - k] - cum[m];
        }
        cout << ans << "\n";
    }
    return 0;
}
