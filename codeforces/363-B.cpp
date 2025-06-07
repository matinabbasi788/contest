// Author: Matin Abbasi
// Date: 2025-03-28
// Description: [Description]

// Includes
#include <bits/stdc++.h>
#include <climits>
#include <iostream>
using namespace std;


// Solve function
void solve(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  int ans = 0;
  for (int i = 0; i < n; i++) cin >> a[i];
  int s = 0, m = 1e9;
  for (int i = 0; i < k; i++) s += a[i];
  if (s < m){
    m = s;
  }
  for (int i = 0; i < n - k; i++){
    s -= a[i];
    s += a[i+k];
    if (s < m){
      ans = i + 1;
      m = s;
    }
  }
  cout << ans + 1 << "\n";
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

