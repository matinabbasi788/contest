// Author: Matin Abbasi
// Date: 2025-04-01
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  int n;
  cin >> n;
  if (n & 3){
    cout << "NO\n";
  } else{
    cout << "YES\n";
  }
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

