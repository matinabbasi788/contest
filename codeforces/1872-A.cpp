// Author: Matin Abbasi
// Date: 2025-03-28
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  int a, b, c, ans = 0;
  cin >> a >> b >> c;
  if (a == b){
    cout << ans << "\n";
  } else if (a > b){
    while (a > b){
      a -= c;
      b += c;
      ans++;
    }
    cout << ans << "\n";
  } else{
    while (b > a){
      b -= c;
      a += c;
      ans++;
    }
    cout << ans << "\n";
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

