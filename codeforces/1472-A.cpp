// Author: Matin Abbasi
// Date: 2025-03-26
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  int w, h, n, sheet = 1;
  cin >> w >> h >> n;
  while (w % 2 == 0){
    w = w / 2;
    sheet *= 2;
  }
  while (h % 2 == 0){
    h = h / 2;
    sheet *= 2;
  }
  if (sheet >= n){
    cout << "YES\n";
  } else{
    cout << "NO\n";
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

