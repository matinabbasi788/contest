// Author: Matin Abbasi
// Date: 2025-04-19
// Description: [Description]

// Includes
#include <bits/stdc++.h>
#include <vector>
using namespace std;


// Solve function
void solve(){
  int n;
  cin >> n;
  vector<int> a(n);
  vector<string> s(n);
  for (int i = 0; i < n; i++){
    cin >> s[i];
  }
  for (int i = 0; i < n; i++){
    a[i] = count(s[i].begin(), s[i].end(), '1');
  }
  for (int i = 1; i < n; i++){
    if (a[i-1] != a[i] && a[i-1] > 0 && a[i] > 0){
      cout << "TRIANGLE\n";
      return;
    }
  }
  cout << "SQUARE\n";
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

