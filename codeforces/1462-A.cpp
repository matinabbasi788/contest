// Author: Matin Abbasi
// Date: 2025-03-25
// Description: [Description]

// Includes
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  int n;
  cin >> n;
  vector<int> a;
  for (int i = 0; i < n; i++){
    int temp;
    cin >> temp;
    a.push_back(temp);
  }
  for (int i = 0; i < (int)a.size()/2; i++) cout << a[i] << " " << a[n - i - 1] << " ";
  if (n % 2 == 1) cout << a[(int)n/2];
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

