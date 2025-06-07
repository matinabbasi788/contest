// Author: Matin Abbasi
// Date: 2025-03-31
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  int a, b;
  cin >> a >> b;
  if (b % 2 == 0 && a % 2 == 0){
    cout << "YES\n";
    return;
  } else if (b % 2 == 1 && a != 0 && a % 2 == 0){
    cout << "YES\n";
    return;
  }
  cout << "NO\n";
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

