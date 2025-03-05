// Author: Matin Abbasi
// Date: 2025-01-19
// Description: [Description]

// Includes
#include <bits/stdc++.h>
using namespace std;


// Solve function
void solve(){

  int n, k;
  cin >> n >> k;

  int a[n];
  int b[n];

  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  
  int p[n];
  p[0] = a[0] * b[0];
  for (int i = 1; i < n; i++){
    p[i] = a[i] * b[i] + p[i - 1];
  }

  int s[n];
  int r = 0;
  for (int i = n - 1; i >= 0; i--){
    r += a[i] * b[i];
    s[i] = r;
  }

  int pref[n];
  r = 0;
  for (int i = 0; i < n; i++){
    r += a[i];
    pref[i] = r;
  }

  int ans = 0;
  for (int i = 0; i + k - 1 < n; i++){
    int cur = 0;
    if (i > 0) cur += p[i - 1];
    if (i + k < n) cur += s[i + k];
    int range_sum = pref[i + k - 1];
    if (i > 0) range_sum -= pref[i - 1];
    cur += range_sum;
    ans = max(ans, cur);
  }

  cout << ans << '\n';
  return;
}


// Main function
int main() {
  int t = 1;
  /*cin >> t;*/
  while(t--){
    solve();
  }
  return 0;
}

