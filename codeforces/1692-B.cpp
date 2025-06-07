// Author: Matin Abbasi
// Date: 2025-04-11
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  int n;
  cin >> n;
  set<int> a;
  int x;
  for (int i = 0; i < n; i++){
    cin >> x;
    a.insert(x);
  }
  if ((n-a.size()) % 2 == 1){
    cout << a.size() - 1 << '\n';
    return;
  }
  cout << a.size() << '\n';
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

