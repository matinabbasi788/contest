#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using PT = array<double, 2>;

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#define dbgarr(...)
#define LINE
#define TIME
#endif

const int MOD = 1000000007;
// const int MOD = 998244353;
const int N =  2e3 + 5;

const double eps = 1e-9;

int sign(double x) {
    return (x > eps) - (x < -eps);
}

double calc(PT a, PT b, PT c) {
    double m = (b[1] - a[1]) / (b[0] - a[0]);
    double y =  m * (c[0] - a[0]) + a[1];
    return fabs(y - c[1]);
}

void solve() {
    int n;
    cin >> n;

    vector<PT> tp(n);
    for (int i = 0; i < n; i++) {
        cin >> tp[i][0] >> tp[i][1];
    }

    double delta;
    cin >> delta;
    
    vector<int> dp(n, 2000);
    dp[0] = 1;
    for (int i = 1; i < n ; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] + 1 < dp[i]) {
                bool f = true; 
                for (int k = j + 1; k < i; k++) {
                    if (sign(calc(tp[i], tp[j], tp[k]) - delta) > 0) {
                        f = false;
                        break;
                    }
                }
                if (f) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }

    cout << dp[n - 1] << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
        LINE
    }
    TIME

    return 0;
}

