// Author: Matin Abbasi
// Date: 2025-04-08
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int dots = 0;
  for (int i = 0; i < n; i++){
    if (s[i] == '.'){
      dots++;
    }
    if (i > 1){
      if(s[i] == '.' && s[i-1] == '.' && s[i-2] =='.'){
        cout << 2 << '\n';
        return;
      }
    }
  }
  cout << dots << '\n';
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

