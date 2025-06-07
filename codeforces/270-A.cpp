// Author: Matin Abbasi
// Date: 2025-03-29
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  int n;
  cin >> n;
  if (360 % (180 - n) == 0){
    cout << "YES" << "\n";
  } else{
    cout << "NO" << "\n";
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

