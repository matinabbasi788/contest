// Author: Matin Abbasi
// Date: 2025-04-08
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


bool is_prime(int n){
  if (n == 1){
    return false;
  }
  if (n == 2){
    return true;
  }
  for (int i = 2; i < pow(n, 0.5) + 1; i++){
    if (n % i == 0) return false;
  }
  return true;
}

// Solve function
void solve(){
  int x, k;
  cin >> x >> k;
  if (x == 1 && k == 2){
    cout << "YES\n";
    return;
  }
  if (k != 1){
    cout << "NO\n";
    return;
  }
  if (is_prime(x)){
    cout << "YES\n";
  } else{
    cout << "NO\n";
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

