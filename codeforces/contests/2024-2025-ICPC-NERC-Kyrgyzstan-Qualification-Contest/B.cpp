// Author: Matin Abbasi
// Date: 2025-04-19
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
  long long ans = 0;
  long long best = 0;
  for (int i = 0; i < n; i++){
    ans += a[i];
    best = min(ans, best);
  }
  cout << abs(best) << '\n';
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

