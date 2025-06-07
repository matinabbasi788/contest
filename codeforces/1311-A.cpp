// Author: Matin Abbasi
// Date: 2025-03-25
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  int a, b;
  cin >> a >> b;
  if (a == b){
    cout << 0 << "\n";
    return;
  }
  if (a < b && (b - a) % 2 == 1){
    cout << 1 << "\n";
    return;
  }
  if (a < b && (b - a) % 2 == 0){
    cout << 2 << "\n";
    return;
  }
  if (a > b && (a - b) % 2 == 1){
    cout << 2 << "\n";
    return;
  }
  if (a > b && (a - b) % 2 == 0){
    cout << 1 << "\n";
    return;
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

