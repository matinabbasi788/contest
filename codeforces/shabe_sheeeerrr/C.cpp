// Author: Matin Abbasi
// Date: 2025-04-17
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


using ll = long long;


// Solve function
void solve(){
  ll n, k;
  cin >> n >> k;
  cout << k + (k-1)/(n-1)<< '\n';
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

