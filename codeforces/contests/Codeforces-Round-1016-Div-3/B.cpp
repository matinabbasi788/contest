// Author: Matin Abbasi
// Date: 2025-04-08
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  string n;
  cin >> n;
  int ans = 0;
  for (int i = n.length(); i > 0; i--){
    if (n[i] == '0') ans++;
    else break;
  }
  for (int i = n.length() - ans + 1; i > 0; i--){
    if (n[i] != '0') ans++;
  }
  cout << ans << '\n';
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

