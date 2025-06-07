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
  int ans = 0;
  for (int i = 1; i < n; i++){
    if (a[i] < a[i-1]) ans++;
  }
  cout << n + ans << '\n';
  cout << a[0] << ' ';
  for (int i = 1; i < n; i++){
    if (a[i] < a[i-1]) cout << 1 << ' ' << a[i] << ' ';
    else cout << a[i] << ' ';
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

