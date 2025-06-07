// Author: Matin Abbasi
// Date: 2025-04-08
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;

const long long a[] = {1000000000, 100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};
// Solve function
void solve(){
  int n;
  cin >> n;
  for (long long x: a){
    if (n >= x){
      cout << n - x << '\n';
      return;
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

