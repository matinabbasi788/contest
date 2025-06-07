#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      a.push_back({x, y});
    }
    int m = 0, ans = 1;
    for (int i = 0; i < a.size(); i++) {
      if (a[i].second > m && a[i].first <= 10){
        m = a[i].second;
        ans = i + 1;
      }
    }
    cout << ans << '\n';
  }
}
