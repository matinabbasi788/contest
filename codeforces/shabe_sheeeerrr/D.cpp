// Author: Matin Abbasi
// Date: 2025-04-17
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
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  int i = 0;
  int j = n;
  int ans = 0;
  int a = 0, b = 0;
  int c = 0;
  while (a){
    for (int i = 0; i <= a.size(); i++){
      c += a[i];
      a[i] = 0;
      if (c)
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

