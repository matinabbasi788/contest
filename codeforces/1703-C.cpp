// Author: Matin Abbasi
// Date: 2025-03-31
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++){
    int nn;
    cin >> nn;
    string s;
    cin >> s;
    for (char x: s){
      if (x == 'D'){
        ++a[i];
        if (a[i] == 10){
          a[i] = 0;
        }
      } else{
        --a[i];
        if (a[i] == -1){
          a[i] = 9;
        }
      }
    }
  }
  for (int i = 0; i < n; i++){
    cout << a[i] << ' ';
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

