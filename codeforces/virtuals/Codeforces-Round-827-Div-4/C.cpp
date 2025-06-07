// Author: Matin Abbasi
// Date: 2025-04-26
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;

char a[8][8];
// Solve function
void solve(){
  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++){
      cin >> a[i][j];
    }
  }
  int r=0;
  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++){
      if(a[i][j] == 'R') r++;
    }
    if (r == 8) break;
    else r = 0;
  }
  if (r==8) cout << 'R' << '\n';
  else cout << 'B' << '\n';
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

