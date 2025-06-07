// Author: Matin Abbasi
// Date: 2025-03-28
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  vector<int> a(3);
  cin >> a[0] >> a[1] >> a[2];
  sort(a.rbegin(), a.rend());
  if (a[0] == a[1]){
    cout << "YES" << "\n";
    cout << a[0] << " " << a[2] << " " << 1 << "\n";
  } else{
    cout << "NO" << "\n";
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

