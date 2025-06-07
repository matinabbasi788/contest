// Author: Matin Abbasi
// Date: 2025-03-27
// Description: [Description]

// Includes
#include <bits/stdc++.h>
#include <cmath>
using namespace std;


typedef long long ll;


// Solve function
void solve(){
  ll n;
  cin >> n;
  ll ans = 0;
  for (int i = 1; i <= n / 2; i++){
    ans += pow(2, i);
  }
  cout << ans << "\n";
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

