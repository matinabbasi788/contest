#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_K = 60;
const int MAX_SUM = 60;
const ll INF = 1LL << 62;

// dp[k][a][b] = min cost to achieve sum A = a, sum B = b using k's up to k
ll dp[MAX_K + 1][MAX_SUM + 1][MAX_SUM + 1];

void precomputeDP() {
    // Initialize base cases
    for (int a = 0; a <= MAX_SUM; a++) {
        for (int b = 0; b <= MAX_SUM; b++) {
            dp[0][a][b] = (a == 0 && b == 0) ? 0 : INF;
        }
    }
    // Fill DP table
    for (int k = 1; k <= MAX_K; k++) {
        ll cost = 1LL << k; // 2^k
        for (int a = 0; a <= MAX_SUM; a++) {
            for (int b = 0; b <= MAX_SUM; b++) {
                // Option 1: Don’t use k
                dp[k][a][b] = dp[k - 1][a][b];
                // Option 2: Use k in A
                if (a >= k) {
                    dp[k][a][b] = min(dp[k][a][b], dp[k - 1][a - k][b] + cost);
                }
                // Option 3: Use k in B
                if (b >= k) {
                    dp[k][a][b] = min(dp[k][a][b], dp[k - 1][a][b - k] + cost);
                }
            }
        }
    }
}

int main() {
    precomputeDP();
    int t;
    cin >> t;
    for (int test = 0; test < t; test++) {
        ll x, y;
        cin >> x >> y;
        ll ans = INF;
        // Try all possible s and t
        for (int s = 0; s <= MAX_SUM; s++) {
            ll x_shifted = (s >= 60) ? 0 : (x >> s);
            for (int t = 0; t <= MAX_SUM; t++) {
                ll y_shifted = (t >= 60) ? 0 : (y >> t);
                if (x_shifted == y_shifted) {
                    ans = min(ans, dp[MAX_K][s][t]);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
