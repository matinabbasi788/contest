// Author: Matin Abbasi
// Date: 2025-05-17
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  int n;
  cin >> n;
  if (n % 2 == 1){
    cout << "NO\n";
    return;
  } else{
    cout << "YES\n";
    while(n){
    cout << "AA";
    n -= 2;
    if (n == 0){
        break;
    }
    cout << "BB";
    n -= 2;
    }
    cout << '\n';
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

