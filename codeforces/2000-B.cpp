// Author: Matin Abbasi
// Date: 2025-04-03
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
  vector<int> b(n+2);
  b[a[0]] = 1;
  for (int i = 1; i < n; i++){
    /*cout << b[a[i]] << '\n';*/
    /*cout << b[a[i]-1]<< ' ' << b[a[i]+1] << '\n';*/
    if (b[a[i]-1] || b[a[i]+1]){
      b[a[i]] = 1;
    } else{
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

