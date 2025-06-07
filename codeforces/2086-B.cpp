// Author: Matin Abbasi
// Date: 2025-04-04
// Description: [Description]

// Includes
#include <bits/stdc++.h>
#include <vector>
using namespace std;

using ll = long long;

// Solve function
void solve(){
  ll n, k, x;
  ll ans = 0;
  cin >> n >> k >> x;
  vector<ll> a(n*k);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  for(int i = n; i < n*k; i++){
    a[i] = a[i-n];
  }
  ll s = 0;
  ll l = 0;
  for (int r = l; r < n*k; r++){
    s += a[r];
    if (s >= x){
      ans += n*k-r;
      cout << ans << ' ' << l << '\n';
      s = 0;
      ++l;
    }
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

