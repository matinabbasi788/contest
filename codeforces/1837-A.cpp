// Author: Matin Abbasi
// Date: 2025-04-01
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  int x, k;
  cin >> x >> k;
  if (x % k == 0){
    cout << 2 << '\n';
    cout << x - k - 1 << ' ' << k + 1 << '\n';
  } else{
    cout << 1 << '\n';
    cout << x << '\n';
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

