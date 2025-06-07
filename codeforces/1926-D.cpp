// Author: Matin Abbasi
// Date: 2025-04-19
// Description: [Description]

// Includes
#include <bits/stdc++.h>
#include <bitset>
#include <string>
#include <vector>
using namespace std;


// Solve function
void solve(){
  int n;
  cin >> n;
  int ans = n;
  vector<char> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++){
    for (int j = i + 1; j < n; j++){
      cout << a[i] & a[j] << '\n';
    }
  }
  cout << ans << '\n';
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

