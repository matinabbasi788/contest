// Author: Matin Abbasi
// Date: 2025-04-19
// Description: [Description]

// Includes
#include <bits/stdc++.h>
#include <vector>
using namespace std;


// Solve function
void solve(){
  int n, k;
  cin >> n >> k;
  if (k == 0){
    cout << n << '\n';
    return;
  }
  int ans = 0;
  vector<int> a(k);
  for (int i = 0; i < k; i++) cin >> a[i];
  for (int i = 1; i <= n; i++){
    ans++;
    if (find(a.begin(), a.end(), i) != a.end()){
      ans *= 2;
    }
  }
  cout << ans << '\n';
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

