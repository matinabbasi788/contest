// Author: Matin Abbasi
// Date: 2025-04-24
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  int n, x;
  cin >> n >> x;
  set<int> a;
  for (int i = 0; i < n; i++){
    if (i != x) cout << i << ' ';
  }
  if (x < n) cout << x;
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

