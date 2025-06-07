// Author: Matin Abbasi
// Date: 2025-04-08
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  string s[8];
  for (int i = 0; i < 8; i++){
    cin >> s[i];
  }
  for (int i = 1; i < 7; i++){
    for (int j = 1; j < 7; j++){
      if (s[i][j] == '#'){
        if (s[i-1][j-1] == '#' && s[i+1][j-1] == '#' && s[i-1][j+1] == '#' && s[i+1][j+1] == '#'){
          cout << i+1 << ' ' << j+1 << '\n';
          return;
        }
      }
    }
  }
}


// Main function
int main() {
  /*ios::sync_with_stdio(0);*/
  /*cin.tie(0);*/
  int t = 1;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}

