// Author: Matin Abbasi
// Date: 2025-03-26
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  int a, b, n, ans = 0;
  cin >> a >> b >> n;
  while (true){
    if (a >= b){
      b += a;
    } else{
      a += b;
    }
    ans++;
    if (a > n || b > n){
      break;
    }
  }
  cout << ans << "\n";
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

