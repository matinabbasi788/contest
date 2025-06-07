// Author: Matin Abbasi
// Date: 2025-04-05
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  string s;
  cin >> s;
  int n = s.length();
  int ans = 0;
  for (int i = 0; i < n; i++){
    for (int j = i+1; j < n; j++){
      for (int k = j+1; k < n; k++){
        if (s[i] == 'Q' && s[j] == 'A' && s[k] =='Q') ++ans;
      }
    }
  }
  cout << ans << '\n';
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

