// Author: Matin Abbasi
// Date: 2025-04-13
// Description: [Description]

// Includes
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;


// Solve function
void solve(){
  int n;
  cin >> n;
  vector<int> a;
  for(int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      int x;
      cin >> x;
      if (find(a.begin(), a.end(), x) == a.end()){
        a.push_back(x);
      }
    }
  }
  for (int i = 1; i <= n * 2; i++){
    if (find(a.begin(), a.end(), i) == a.end()){
      cout << i << ' ';
    }
  }
  for (int i = 0; i < (int) a.size(); i++){
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

