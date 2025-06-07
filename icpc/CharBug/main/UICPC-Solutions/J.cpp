#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 22, MAXM = 10;
ll dp[MAXN][MAXM][MAXM][2];
ll get (ll x) {
	string v = to_string(x);
	if (x < 10) return 1LL + x;
	for (int i = 0;i < MAXN;i ++) {
		for (int j = 0;j < MAXM;j ++) {
			for (int k = 0;k < MAXM;k ++) {
				dp[i][j][k][0] = dp[i][j][k][1] = 0;
			}
		}
	}

	int N = v.size();
	reverse (v.begin(), v.end());
	// for (auto x : v) cout << x << " ";
	// cout << "\n";

	ll ans = 10;
	for (int a = 0;a < MAXM;a ++) {
		for (int b = 0;b < MAXM;b ++) {
			if (a == b) continue;
			if ((a < (v[1] - '0')) || (a <= (v[1] - '0') && b <= (v[0] - '0'))) {
				dp[1][a][b][0] ++;
			} else {
				dp[1][a][b][1] ++;
			}
		}
	}
	for (int i = 2;i < N;i ++) {
		for (int a = 0;a < MAXM;a ++) {
			for (int b = 0;b < MAXM;b ++) {
				for (int c = 0;c < MAXM;c ++) {
					if ((a == b) || (b == c) || (a == c)) continue;
					if (a < (v[i] - '0')) {
						dp[i][a][b][0] += dp[i - 1][b][c][0] + dp[i - 1][b][c][1];
					} else if (a == (v[i] - '0')) {
						dp[i][a][b][0] += dp[i - 1][b][c][0];
						dp[i][a][b][1] += dp[i - 1][b][c][1];
					} else {
						dp[i][a][b][1] += dp[i - 1][b][c][0] + dp[i - 1][b][c][1];
					}
				}
			}
		}
	}
	// for (int i = 1;i < N;i ++) {
	//     for (int x = 0;x < 10;x ++) {
	//         for (int y = 0;y < 10;y ++) {
	//             cout << dp[i][x][y][0] << " " << dp[i][x][y][1] << " | ";
	//         } cout << "\n";
	//     } cout << "\n";
	// } cout << "\n";
	for (int i = 1;i < N;i ++) {
		for (int a = 1;a < MAXM;a ++) {
			for (int b = 0;b < MAXM;b ++) if (a != b) {
				ans += dp[i][a][b][0];
				if (i != N - 1) ans += dp[i][a][b][1];
			}
		}
	}
	return ans;
};

int check (ll x) {
	string v = to_string(x);
	reverse (v.begin(), v.end());
	for (int i = 1;i < v.size();i ++) if (v[i - 1] == v[i]) return 0;
	for (int i = 2;i < v.size();i ++) if (v[i - 2] == v[i]) return 0;
	return 1;
}

int32_t main () {

	ios_base::sync_with_stdio(0); 
	cin.tie(0); 
	cout.tie(0); 

	ll A, B;
	cin >> A >> B;
	// cout << A << " " << B << "\n";
	ll ans = get (B) - get (A) + check (A);
	// cout << get (to_string(B)) << " " << get (to_string(A)) << " " << check (to_string(A)) << "\n";
	cout << ans << "\n";
}

