// Author: Matin Abbasi
// Date: 2025-03-28
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;

//typedef
typedef long long ll;

// Solve function
void solve(){
  ll r, g, b;
  cin >> r >> g >> b;
  ll res = min({(r + g + b) / 3, r + g, g + b, b + r});
  cout << res << "\n";
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

