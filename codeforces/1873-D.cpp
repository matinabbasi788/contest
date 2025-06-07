// Author: Matin Abbasi
// Date: 2025-04-01
// Description: [Description]

// Includes
#include <bits/stdc++.h>
#include <cmath>
using namespace std;


// Solve function
void solve(){
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int ans = 0;
  int i = 0;
  while (i < n){
    if (s[i] == 'B'){
      i += k;
      ++ans;
    } else{
      ++i;
    }
  }
  cout << ans << '\n';
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

