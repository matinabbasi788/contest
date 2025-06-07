// Author: Matin Abbasi
// Date: 2025-04-13
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  int n, m, l, r;
  cin >> n >> m >> l >> r;
  int lp = 0, rp = 0;
  for (int i = 0; i < m; i++){
    if (rp < r){
      rp++;
    } else{
      lp--;
    }

  }
  cout << lp << ' ' << rp << '\n';
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

