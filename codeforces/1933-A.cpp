// Author: Matin Abbasi
// Date: 2025-03-30
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++){
    int temp;
    cin >> temp;
    ans += abs(temp);
  }
  cout << ans << '\n';
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

