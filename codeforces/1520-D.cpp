// Author: Matin Abbasi
// Date: 2025-03-28
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

// Solve function
void solve(){
  int n;
  cin >> n;
  map<int, int> a;
  ll res = 0;
  for (int i = 0; i < n; i++){
    int x;
    cin >> x;
    x -= i;
    res += a[x];
    a[x]++;
  }
  cout << res << "\n";
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

