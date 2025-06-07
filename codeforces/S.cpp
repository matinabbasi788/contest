// Author: Matin Abbasi
// Date: 2025-04-28
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  int n;
  cin >> n;
  vector<int> a(n);
  int c = 0;
  int ans = 0;
  for (int i = 0; i < n; i++){
    c += a[i];
    int b = c;
    for (int j = 0; j < n; j++){
      b -= a[j];
      if (b == 0){

      }
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

