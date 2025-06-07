// Author: Matin Abbasi
// Date: 2025-04-01
// Description: [Description]

// Includes
#include <bits/stdc++.h>
#include <cmath>
using namespace std;


// Solve function
void solve(){
  int n, m, ans = 0;
  cin >> n >> m;
  for (int i = 0; i <= 1000; i++){
    for (int j = 0; j <= 1000; j++){
      if ((pow(i, 2) + j == n) && (i + pow(j, 2) == m)){
        ++ans;
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

