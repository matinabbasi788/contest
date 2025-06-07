// Author: Matin Abbasi
// Date: 2025-04-26
// Description: [Description]

// Includes
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


using ll = long long;

// Solve function
void solve(){
  int n;
  cin >> n;
  vector<ll> a(n);
  map<ll, ll> b;
  for (int i = 0; i < n; i++){
    cin >> a[i];
    b[a[i]] = i;
  }
  ll m = -1;
  for (auto i:b){
    for (auto j:b){
      if (gcd(i.first, j.first) == 1){
        m = max(m, i.second + j.second + 2); 
      }
    }
  }
  cout << m << '\n';
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

