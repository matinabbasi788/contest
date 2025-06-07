// Author: Matin Abbasi
// Date: 2025-04-17
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  string s;
  cin >> s;
  int ans;
  for (int i = 0; i < (int) s.length(); i++){
    if (s[i] != 0){
      ans++;
    }
  }
  cout << ans << '\n';
  for (int i = 0; i < (int) s.length(); i++){
    if (s[i] != 0){
      cout << s[i] << pow(10, s.length() - i) << ' ';
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

