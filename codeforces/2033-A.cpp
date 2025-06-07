// Author: Matin Abbasi
// Date: 2025-04-02
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  int n;
  cin >> n;
  int x = 0;
  int i = 1;
  while (1){
    if (i % 2 == 1){
      x += -(2 * i - 1);
    } else{
      x += 2 * i - 1;
    }
    if (x > n && x > 0){
      cout << "Kosuke\n";
      break;
    }
    if (x < -n && x < 0){
      cout << "Sakurako\n";
      break;
    }
    ++i;
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

