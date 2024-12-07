#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> g(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }

    vector dp(n, vector<int>(m));
    int ans = 0;
    for (int i = 0; i  < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i != 0) {
                dp[i][j] = dp[i - 1][j];
                if (j - 1 >= 0) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
                }
                if (j + 1 < m) {
                    dp[i][j] = max(dp[i][j], dp[i  - 1][j + 1]);
                }
            }
            if (g[i][j] == 'B') {
                dp[i][j]++;
            }
            if (g[i][j] == 'W') {
                ans = max(ans, dp[i][j]);   

                dp[i][j] = 0;
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
    }

    return 0;
}
