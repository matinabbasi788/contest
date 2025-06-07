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
  int dif = 1e9 + 5;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  for (int i = 1; i < n; i++){
    dif = min(abs(abs(a[i-1]) - abs(a[i])), dif);
    if (a[i-1] > a[i]){
      cout << 0 << '\n';
      return;
    }
  }
  cout << abs(dif / 2) + 1 << '\n';
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

