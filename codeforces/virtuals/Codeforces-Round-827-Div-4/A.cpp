// Author: Matin Abbasi
// Date: 2025-04-26
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  int a, b, c;
  cin >> a >> b >> c;
  if (a == b+c || b == a + c || c == a+b){
    cout << "YES\n";
  }else{
    cout << "NO\n";
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

