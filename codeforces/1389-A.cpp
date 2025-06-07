// Author: Matin Abbasi
// Date: 2025-03-25
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Solve function
void solve(){
  ll l, r;
  cin >> l >> r;
  for (ll i = l; i < r; i++){
    if (i * 2 > r){
      cout << -1 << " " << -1 << "\n";
      break;
    } else{
      cout << i << " " << i * 2 << "\n";
      break;
    }
  }
  
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

