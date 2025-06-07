#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve_kaitenzushi() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> d(n);
        
        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }

        int window_size = 2 * k + 1;
        vector<long long> dp(window_size, -1e18);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            vector<long long> next_dp(window_size, -1e18);

            for (int r = 0; r < window_size; r++) {
                if (dp[r] == -1e18) continue;

                next_dp[r] = max(next_dp[r], dp[r]);

                if (r + k < window_size) {
                    next_dp[r + k] = max(next_dp[r + k], dp[r] + d[i]);
                }

                if (r > 0) {
                    next_dp[r - 1] = max(next_dp[r - 1], dp[r]);
                }
            }

            dp = next_dp;
        }

        cout << dp[0] << "\n";
    }
}

int main() {
    solve_kaitenzushi();
    return 0;
}
