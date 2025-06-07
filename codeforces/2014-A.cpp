// Author: Matin Abbasi
// Date: 2025-03-28
// Description: [Description]

// Includes
#include <bits/stdc++.h>
#include <vector>
using namespace std;


// Solve function
void solve(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  int ans = 0, c = 0;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++){
    if (a[i] >= k){
      c += a[i];
    } else if (a[i] == 0 && c > 0){
      ans++;
      c--;
    }
  }
  cout << ans << "\n";
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

