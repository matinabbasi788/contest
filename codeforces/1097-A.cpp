// Author: Matin Abbasi
// Date: 2025-03-28
// Description: [Description]

// Includes
#include <bits/stdc++.h>
#include <vector>
using namespace std;


// Solve function
void solve(){
  char a, b;
  cin >> a >> b;
  vector<pair<char, char>> c(5);
  for (int i = 0; i < 5; i++){
    cin >> c[i].first >> c[i].second;
  }
  for (int i = 0; i < 5; i++){
    if (c[i].first == a || c[i].second == b){
      cout << "YES" << "\n";
      return;
    }
  }
  cout << "NO" << "\n";
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

