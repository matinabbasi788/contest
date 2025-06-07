// Author: Matin Abbasi
// Date: 2025-04-26
// Description: [Description]

// Includes
#include <bits/stdc++.h>
#include <vector>
using namespace std;


using ll = long long;

// Solve function
void solve(){
  ll n, q;
  cin >> n >> q;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<ll> k(n);
  for (int i = 0; i < q; i++) cin >> k[i];
  for (int i = 0; i < q; i++){
    ll ans = 0;
    for (int j = 0; j < n; j++){
      if (k[i] >= a[j]) ans += a[j];
      else break;
    }
    cout << ans << ' ';
  }
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

