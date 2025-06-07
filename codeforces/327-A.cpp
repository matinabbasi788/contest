// Author: Matin Abbasi
// Date: 2025-04-06
// Description: [Description]

// Includes
#include <bits/stdc++.h>
#include <vector>
using namespace std;


// Solve function
void solve(){
  int n;
  cin >> n;
  vector<int> a(n);
  int ans = 0, ones = 0, best = 0;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++){
    if (a[i] == 1){
      ones++;
    }
  }
  ans = ones;
  for (int ii = 0; ii < n; ii++){
    for (int i = ii; i < n; i++){
      if (a[i] == 1) ans--;
      if (a[i] == 0) ans++;
      best = max(ans, best);
    }
    ans = ones;
  }
  cout << best << '\n';
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

