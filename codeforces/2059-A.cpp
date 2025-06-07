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
  set<int> b;
  for (int i = 0; i < n; i++){
    int x;
    cin >> x;
    a.insert(x);
  }
  for (int i = 0; i < n; i++){
    int x;
    cin >> x;
    b.insert(x);
  }
  if (a.size() + b.size() > 3){
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

