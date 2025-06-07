// Author: Matin Abbasi
// Date: 2025-04-02
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  int a, b, c;
  cin >> a >> b >> c;
  int diff = abs(a - b);
  if (diff*2 < a || diff*2 < b || diff*2 < c){
    cout << -1 << '\n';
    return;
  }
  if (c > diff){
    cout << c - diff << '\n';
  } else{
    cout << c + diff << '\n';
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

