// Author: Matin Abbasi
// Date: 2025-04-01
// Description: [Description]

// Includes
#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;


// Solve function
void solve(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int m = *max_element(a.begin(), a.end());
  vector<int> b, c;
  for (int i = 0; i < n; i++){
    if (a[i] != m){
      b.push_back(a[i]);
    } else{
      c.push_back(a[i]);
    }
  }
  if (b.empty() || c.empty()){
    cout << -1 << '\n';
    return;
  }
  cout << b.size() << ' ' << c.size() << '\n';
  for (int x: b) cout << x << ' ';
  cout << '\n';
  for (int x: c) cout << x << ' ';
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

