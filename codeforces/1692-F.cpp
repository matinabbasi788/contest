// Author: Matin Abbasi
// Date: 2025-04-11
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  int n;
  cin >> n;
  vector<int> cnt(10, 0);
  for (int i = 0; i < n; i++){
    int x;
    cin >> x;
    cnt[x % 10]++;
  }
  vector<int> a;
  for (int i = 0; i < 10; i++){
    for (int j = 0; j < min(cnt[i] , 3); j++){
      a.push_back(i);
    }
  }
  int m = a.size();
  for (int i = 0; i < m; i++){
    for (int j = i+1; j < m; j++){
      for (int k = j+1; k < m; k++){
        if ((a[i] + a[j] + a[k]) % 10 == 3){
          cout << "YES\n";
          return;
        }
      }
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

