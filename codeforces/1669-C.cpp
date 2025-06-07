// Author: Matin Abbasi
// Date: 2025-04-01
// Description: [Description]

// Includes
#include <bits/stdc++.h>
#include <vector>
using namespace std;


// Solve function
void solve(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int x = a[0] % 2;
  int y = a[1] % 2;
  for (int i = 0; i < n; i += 2){
    if (a[i] % 2 != x){
      cout << "NO\n";
      return;
    }
  }
  for (int i = 1; i < n; i += 2){
    if (a[i] % 2 != y){
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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

