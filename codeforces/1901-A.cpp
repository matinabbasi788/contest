// Author: Matin Abbasi
// Date: 2025-03-27
// Description: [Description]

// Includes
#include <bits/stdc++.h>
#include <vector>
using namespace std;


// Solve function
void solve(){
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  int ans = (x - a[n-1]) * 2;
  for (int i = 0; i < n - 1; i++){
    if (a[i+1] - a[i] > ans){
      ans = a[i+1] - a[i];
    }
  }
  if (a[0] > ans){
    ans = a[0];
  }
  cout << ans << "\n";
}


// Main function
int main() {
  /*ios::sync_with_stdio(0);*/
  /*cin.tie(0);*/
  int t = 1;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}

