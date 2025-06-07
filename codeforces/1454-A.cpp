// Author: Matin Abbasi
// Date: 2025-03-27
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  int n;
  cin >> n;
  if (n % 2 == 0){
    for (int i = n; i > 0; i--){
      cout << i << " ";
    }
  } else{
    for (int i = n - 1; i > n/2; i--){
      cout << i << " ";
    }
    cout << n << " ";
    for (int i = n/2; i > 0; i--){
      cout << i << " ";
    }
  }
  cout << "\n";
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

