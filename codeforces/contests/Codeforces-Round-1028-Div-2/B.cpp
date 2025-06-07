// Author: Matin Abbasi
// Date: 2025-05-31
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 998244353;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<ll> p(n), q(n), ans;
    for (int i = 0; i < n; ++i)
      cin >> p[i];
    for (int i = 0; i < n; ++i)
      cin >> q[i];

    vector<ll> pow_p(n), pow_q(n);
    for (int i = 0; i < n; ++i) {
      pow_p[i] = 1LL << p[i]; // 2^p[i]
      pow_q[i] = 1LL << q[i]; // 2^q[i]
    }

    for (int i = 0; i < n; ++i) {
      vector<ll> temp;
      int a = 0, b = i;
      for (int j = 0; j <= b; ++j) {
        temp.push_back((pow_p[a] + pow_q[b]) % MOD);
        a++;
        b--;
      }
      ans.push_back(*max_element(temp.begin(), temp.end()));
    }

    for (int i = 0; i < ans.size(); ++i) {
      cout << ans[i];
      if (i < ans.size() - 1)
        cout << " ";
    }
    cout << "\n";
  }
  return 0;
}
