// Author: Matin Abbasi
// Date: 2025-04-12
// Description: [Description]

// Includes
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;


// Solve function
void solve(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  set<int> b;
  for (int i = 0; i < n; i++){
    b.insert(a[i]);
  }
  vector<int> v;
  if ((int)b.size() >= k){
    cout << "YES\n";
    for (auto x: b){
      int i = 1;
      for (auto y: a){
        if (x == y && find(v.begin(), v.end(), x) == v.end()){
          cout << i << ' ';
          v.push_back(x);
        }
        i++;
      }
    }
  }
  else cout << "NO\n";
}


// Main function
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  /*cin >> t;*/
  while(t--){
    solve();
  }
  return 0;
}

