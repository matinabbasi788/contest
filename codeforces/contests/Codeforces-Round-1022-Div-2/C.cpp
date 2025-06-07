// Author: Matin Abbasi
// Date: 2025-05-01
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 0; i < n; ){
    int j = i;
    while(j+1<n && a[j+1] == a[i]){
      j++;
    }
    long long v = a[i];
    bool left_ok = (i==0) || (a[i-1] < v);
    bool right_ok = (j == n - 1) || (a[j+1]<v);
    if (left_ok && right_ok){
      ++ans;
    }
    i = j + 1;
  }
  cout << ans << '\n';
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

