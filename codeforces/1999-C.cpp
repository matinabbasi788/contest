// Author: Matin Abbasi
// Date: 2025-03-31
// Description: [Description]

// Includes
#include <bits/stdc++.h>
#include <vector>
using namespace std;


// Solve function
void solve(){
  int n, s, m;
  cin >> n >> s >> m;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i].first >> a[i].second;
  }
  if (a[0].first >= s){
    cout << "YES\n";
    return;
  }
  if (m - a[n-1].second >= s){
    cout << "YES\n";
    return;
  }
  for (int i = 1; i < n; i++){
    if (a[i].first - a[i-1].second >= s){
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
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

