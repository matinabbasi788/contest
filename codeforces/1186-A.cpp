// Author: Matin Abbasi
// Date: 2025-03-30
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  int n, m, k;
  cin >> n >> m >> k;
  if (min(m, k) >= n){
    cout << "YES\n";
  } else{
    cout << "NO\n";
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

