// Author: Matin Abbasi
// Date: 2025-04-27
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve() {
  int n;
  cin >> n;

  vector<int> ath(n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 5; j++)
      cin >> ath[i];

  int gold = 0;
  for (int i = 1; i < n; i++) {
    if (ath[i] < ath[gold])
      gold = i;
  }

  for (int i = 0; i < n; i++) {
    if (i == gold)
      continue;
    if (ath[i] < ath[gold]) {
      cout << -1 << "\n";
      return;
    }
  }
  cout << gold + 1 << "\n";
}

// Main function
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
