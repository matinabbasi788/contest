// Author: Matin Abbasi
// Date: 2025-03-28
// Description: [Description]

// Includes
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;



// Solve function
void solve(){
  int m, s;
  cin >> m >> s;
  if (s == 0){
    if (m == 1){
      cout << "0 0\n";
    } else{
      cout << "-1 -1\n";
    }
    return;
  }
  if (s > 9 * m){
    cout << "-1 -1\n";
    return;
  }
  vector<int> smallest(m), largest(m);
  int sum = s;
  for (int i = 0; i < m; i++){
    int digit = min(9, sum);
    largest[i] = digit;
    sum -= digit;
  }
  sum = s;
  for (int i = m - 1; i >= 0; i--){
    int digit = max(0, sum - 9 * i);
    if (i == 0 && digit == 0) digit = 1;
    smallest[i] = digit;
    sum -= digit;
  }
  for (int x: smallest) cout << x;
  cout << " ";
  for (int x: largest) cout << x;
  cout << '\n';
}


// Main function
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  /*cin >> t;*/
  while(t--){
    solve();
  }
  return 0;
}

