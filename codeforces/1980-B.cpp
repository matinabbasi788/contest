// Author: Matin Abbasi
// Date: 2025-04-03
// Description: [Description]

// Includes
#include <bits/stdc++.h>
#include <vector>
using namespace std;


// Solve function
void solve(){
  int n, f, k;
  cin >> n >> f >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int f_val = a[f-1];
  sort(a.rbegin(), a.rend());
  for(int i = 0; i < k; i++){
    if (a[i] == f_val && a[k] == f_val && k != n){
      cout << "MAYBE\n";
      return;
    }
    if ((a[i] == f_val && a[k] != f_val) || k == n){
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
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

