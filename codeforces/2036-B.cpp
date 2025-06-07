// Author: Matin Abbasi
// Date: 2025-04-11
// Description: [Description]

// Includes
#include <bits/stdc++.h>
#include <vector>
using namespace std;


// Solve function
void solve(){
  int n, k;
  cin >> n >> k;
  vector<int> summ(k);
  vector<pair<int, int>> a(k);
  for (int i = 0; i < k; i++){
    cin >> a[i].first >> a[i].second;
    summ[a[i].first-1] += a[i].second;
  }
  sort(summ.rbegin(), summ.rend());
  int ans = 0;
  for (int i = 0; i < min(n, k); i++){
    ans += summ[i];
  }
  cout << ans << '\n';
}


// Main function
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}

