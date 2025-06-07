// Author: Matin Abbasi
// Date: 2025-04-01
// Description: [Description]

// Includes
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;


// Solve function
void solve(){
  int n;
  cin >> n;
  vector<long long> ans;
  for (int i = 30; i >= 0; --i){
    ans.push_back(pow(2, i));
  }
  for (int x: ans){
    if (n >= x){
      cout << x - 1 << '\n';
      return;
    }
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

