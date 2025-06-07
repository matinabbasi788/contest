// Author: Matin Abbasi
// Date: 2025-04-12
// Description: [Description]

// Includes
#include <bits/stdc++.h>
#include <vector>
using namespace std;


// Solve function
void solve(){
  string s;
  cin >> s;
  int m;
  cin >> m;
  vector<int> dp(10e5+10);
  int tt = 0;
  for (int i = 0; i < (int)s.length(); i++){
    if (s[i] == s[i+1]){
    tt++;
    dp[i] = tt;
    cout << dp[i] << '\n';
    }
  }
  cout << "##############\n";
  for (int q = 0; q < m; q++){
    int l, r;
    cin >> l >> r;
    cout << dp[l] - dp[r] << '\n';
  }
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

