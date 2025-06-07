// Author: Matin Abbasi
// Date: 2025-04-26
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  int n;
  cin >> n;
  set<int> a;
  for (int i = 0; i < n; i++){
    int x;
    cin >> x;
    a.insert(x);
  }
  if ((int)a.size() == n){
    cout << "YES\n";
  } else{
    cout << "NO\n";
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

