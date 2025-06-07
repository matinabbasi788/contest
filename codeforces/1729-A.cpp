// Author: Matin Abbasi
// Date: 2025-03-27
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  int a, b, c;
  cin >> a >> b >> c;
  if (abs(b-c) + c - 1 == a - 1) cout << 3 << "\n";
  else if (a - 1 < abs(b-c) + c - 1) cout << 1 << "\n";
  else cout << 2 << "\n";
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

