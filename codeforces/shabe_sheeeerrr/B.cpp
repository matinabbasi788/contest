// Author: Matin Abbasi
// Date: 2025-04-17
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  int n, k;
  cin >> n >> k;
  int tt = n - (k - 1);
  if (tt > 0 && tt % 2 == 1){
    cout << "YES" << '\n';
    for (int i = 0; i < k - 1; i++){
      cout << "1 ";
    }
    cout << tt << '\n';
    return;
  }
  tt = n - 2 * (k - 1);
  if (tt > 0 && tt % 2 == 0){
    cout << "YES" << '\n';
    for (int i = 0; i < k - 1; i++){
      cout << "2 ";
    }
    cout << tt << '\n';
    return;
  }
  cout << "NO" << '\n';
    
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

