// Author: Matin Abbasi
// Date: 2025-03-30
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  string s, t;
  cin >> s;
  cin >> t;
  int i = 0;
  for(auto x: t){
    if (x == s[i]){
      i++;
    }
  }
  cout << i+1 << '\n';
}


// Main function
int main() {
  /*ios::sync_with_stdio(0);*/
  /*cin.tie(0);*/
  int t = 1;
  /*cin >> t;*/
  while(t--){
    solve();
  }
  return 0;
}

