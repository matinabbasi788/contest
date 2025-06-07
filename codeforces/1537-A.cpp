// Author: Matin Abbasi
// Date: 2025-03-30
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  int k;
  cin >> k;
  int s = 0;
  for (int i = 0; i < k; i++){
    int temp;
    cin >> temp;
    s += temp;
  }
  if (s < k){
    cout << 1 << '\n';
  } else{
    cout << s - k << '\n';
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

