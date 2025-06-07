// Author: Matin Abbasi
// Date: 2025-03-28
// Description: [Description]

// Includes
#include <bits/stdc++.h>
#include <vector>
using namespace std;


// Solve function
void solve(){
  int n, m;
  cin >> n >> m;
  vector<pair<pair<int, int>, int>> a(m);
  for (int i = 0; i < m; i++){
    cin >> a[i].first.first >> a[i].first.second >> a[i].second;
  }
  for (int i = 0; i < m; i++){
    cout << a[i].first.first << " " << a[i].first.second << " " << a[i].second << "\n";
  }
}


// Main function
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  /*cin >> t;*/
  while(t--){
    solve();
  }
  return 0;
}

