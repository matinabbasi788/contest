// Author: Matin Abbasi
// Date: 2025-03-29
// Description: [Description]

// Includes
#include <bits/stdc++.h>
#include <vector>
using namespace std;


// Solve function
void solve(){
  vector<int> a;
  string s;
  cin >> s;
  for (char x: s){
    int temp = atoi(&x);
    a.push_back(temp);
  }
  if (a.size() >= 3){
    if (a[0] == 1 && a[1] == 0 && a[2] != 0){
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
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

