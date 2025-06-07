// Author: Matin Abbasi
// Date: 2025-03-30
// Description: [Description]

// Includes
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  int a[3];
  for (int i = 0; i < 3; i++){
    cin >> a[i];
  }
  int m = *max_element(a, a + 3);
  int b = 0;
  for (int i = 0; i < 3; i++){
    if (a[i] == m){
      ++b;
    }
  }
  for (int i = 0; i < 3; i++){
    if (a[i] == m && b > 1){
      cout << 1 << ' ';
    }
    else if (a[i] == m && b == 1){
      cout << 0 << ' ';
    }
    else {
      cout << m - a[i] + 1 << ' ';
    }
  }
  cout << '\n';
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

