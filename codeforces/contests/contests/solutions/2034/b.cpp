// Author: Matin Abbasi
// Date: {{DATE}}
// Description: [Description]

// Includes
#include <bits/stdc++.h>
#include <cmath>
#include <string>
using namespace std;

const int xn = 2e5 + 10;

int n, m, k, ps[xn];
string s;


// Solve function
void solve(){
  cin >> n >> m >> k >> s;
  fill(ps, ps + n, 0);
  int ans = 0, cnt = 0, sum = 0;
  for (int i = 0; i < n; i++){
    sum += ps[i];
    if (sum || s[i] == '1') cnt = 0;
    else{
      cnt++;
      if (cnt == m){
        sum++, ans++, cnt=0;
        if (i + k < n) ps[i + k]--;
      }
    }
  }
  cout << ans << '\n';

}
// Main function
int main() {
  int t = 1;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
